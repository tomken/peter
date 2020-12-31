#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Node {
public:
    int   value;
    Node* next;
};

class List {
public:
    List() {
        printf("链表被创造了\n");
        _head = 0;
        _tail = 0;
    }

    ~List() {
        printf("链表被删除了\n");
    }

public:
    void push_front(int value) {
        if (_head) {
            Node* node = new Node(); // 创建新的节点
            node->value = value;     // 给节点赋予数据
            node->next = _head;      // 把该节点的下一个指向头
            _head = node;            // 把链表的头指向该节点
        } else {
            _head = new Node();      // 创建新的节点
            _head->value = value;    // 给节点赋予数据
            _head->next = 0;         // 把该节点的下一个指向空
            _tail = _head;
        }
    }

    void push_back(int value) {
        if (_tail) {
            Node* node = new Node(); // 创建新的节点
            node->value = value;     // 给节点赋予数据
            node->next = 0;          // 把该节点的下一个指向空
            _tail->next = node;      //把尾指向这个节点
            _tail = node;            // 把链表的尾指向该节点
        } else {
            _head = new Node();      // 创建新的节点
            _head->value = value;    // 给节点赋予数据
            _head->next = 0;         // 把该节点的下一个指向空
            _tail = _head;
        }
    }

    void pop_front() {
        if (!_head) {
            return;
        }

        Node* n = _head->next;
        delete _head;
        
        if (n) {
            _head = n;
        } else {
            _head = 0;
            _tail = 0;
        }
    }

    void pop_back() {
        if (!_head) {
            return;
        }

        while (1) {
            Node* p = _head;
            Node* n = p->next;

            if (n == _tail) {
                _tail = p;
                _tail->next = 0;
                delete n;
                return;
            }

            if (!n) {
                delete _head;
                _head = 0;
                _tail = 0;
                return;
            }
        }
    }

    void dump() {
        Node* n = _head;
        while (n) {
            printf("===> %d\n", n->value);
            n = n->next;
        }
    }

private:
    Node* _head;
    Node* _tail;

};

int main(int argc, char* argv[]) {
    List* list = new List();

    // for (int i=0; i<10; i++) {
    //     list->push_back(i + 100);
    // }

    // list->pop_front();
    // list->pop_back();

    list->push_back(2);
    list->push_back(3);
    list->pop_back();
    list->push_back(1);

    list->dump();

    delete list;
    return 0;
}