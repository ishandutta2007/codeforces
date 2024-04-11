#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18 + 7;

struct TNode {
    TNode *left, *right;
    int term;
};

TNode *new_node() {
    return new TNode({nullptr, nullptr, 1});
}

void add(TNode *root, string &s) {
    root->term++;
    for (char c : s) {
        if (c == '0') {
            if (!root->left) {
                root->left = new_node();
            } else {
                root->left->term++;
            }
            root = root->left;
        } else {
            if (!root->right) {
                root->right = new_node();
            } else {
                root->right->term++;
            }
            root = root->right;
        }
    }
}

void remove(TNode *&root, string &s, int i) {
    if (i == s.size()) {
        root->term--;
        if (!root->term) {
            root = nullptr;
        }
        return;
    }
    if (s[i] == '0') {
        remove(root->left, s, i + 1);
    } else {
        remove(root->right, s, i + 1);
    }
    root->term--;
    if (!root->term) {
        root = nullptr;
    }
}

string xor1(TNode *root, string &s) {
    string new_s = "";
    string xor_s = "";
    for (char c : s) {
        if (c == '0') {
            if (root->right) {
                new_s += '1';
                //xor_s += '1';
                root = root->right;
            } else if (root->left) {
                new_s += '0';
                //xor_s += '0';
                root = root->left;
            }
        } else {
            if (root->left) {
                new_s += '1';
                //xor_s += '0';
                root = root->left;
            } else if (root->right) {
                new_s += '0';
                //xor_s += '1';
                root = root->right;
            }
        }
    }
    //cout << xor_s << endl;
    return new_s;
}

string i_to_s(int x) {
    string s = "";
    long long k = (long long) (1 << 30);
    while (k != 0) {
        s += (char) (x / k + '0');
        x %= k;
        k /= 2;
    }
    return s;
}

int s_to_i(string &s) {
    int sum = 0;
    long long k = (long long) (1 << 30);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            sum += k;
            //cout << k << endl;
        }
        k /= 2;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    TNode *root = new_node();
    TNode *node = root;
    for (int i = 0; i <= 30; i++) {
        node->left = new_node();
        node = node->left;
    }
    for (int i = 0; i < n; i++) {
        char c;
        int k;
        cin >> c >> k;
        string s = i_to_s(k);
        //cout << s << endl;
        if (c == '+') {
            add(root, s);
            //cout << s << endl;
        } else if (c == '-') {
            remove(root, s, 0);
            //cout << s << endl;
        } else {
            string s1 = xor1(root, s);
            //cout << s1 << endl;
            cout << s_to_i(s1) << endl;
        }
    }
}