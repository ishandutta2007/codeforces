/*
    Soheil Mohammadkhani
*/
#include <bits/stdc++.h>

using namespace std;

struct node {
    node* next = nullptr;
    int data;
};

struct m_stack {
    node* top;
    int sz = 0;
    void push(int a) {
        node* tmpnode = new node;
        tmpnode -> next = top;
        tmpnode -> data = a;
        top = tmpnode;
        sz++;
    }

    bool pop() {
        if (sz > 0) {
            top = top -> next;
            sz--;
        }
    }

    int get_top() {
        return top->data;
    }
};

int main() {
    m_stack m;
    string s;
    cin >> s;

    for (string::iterator i = s.begin(); i != s.end(); i++) {
        char c = *i;
//        if (c == '{') m.push(0);
//        if (c == '[') m.push(1);
//        if (c == '(') m.push(2);
//        if (c == '}') {
//            if (m.sz <= 0 || m.get_top() != 0) return cout << "NO" << endl, 0;
//            m.pop();
//        }
//
//        if (c == ']') {
//            if (m.sz <= 0 || m.get_top() != 1) return cout << "NO" << endl, 0;
//            m.pop();
//        }
//
//        if (c == ')') {
//            if (m.sz <= 0 || m.get_top() != 2) return cout << "NO" << endl, 0;
//            m.pop();
//        }

        if (c == '+') {
            if (m.sz > 0 && m.get_top() == '+') {
                m.pop();
            } else {
                m.push('+');
            }
        }

        if (c == '-') {
            if (m.sz > 0 && m.get_top() == '-') {
                m.pop();
            } else {
                m.push('-');
            }
        }
    }

    if (m.sz > 0) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}