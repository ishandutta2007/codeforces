#include <bits/stdc++.h>
using namespace std;

struct btrie {
    int cnt;
    btrie *left, *right;

    btrie() { cnt = 0; left = nullptr; right = nullptr;}

    void add(int n, int b = 30) {
        cnt++;
        if(b >= 0) {
            if(n & (1 << b)) {
                if(!right)
                    right = new btrie();

                right->cnt++;
                right->add(n, b - 1);
            }
            else {
                if(!left)
                    left = new btrie();

                left->cnt++;
                left->add(n, b - 1);
            }
        }
    }

    void rem(int n, int b = 30) {
        cnt--;
        if(b >= 0) {
            if(n & (1 << b)) {
                right->cnt--;
                right->rem(n, b - 1);
            }
            else {
                left->cnt--;
                left->rem(n, b - 1);
            }
        }
    }

    void best(int n, int &out, int b = 30) {
        int t = ((n & (1 << b)) ? 1 : 0);
        if(b < 0)
            return;
        if(t == 1) {
            if(right && right->cnt > 0) {
                out |= (1 << b);
                right->best(n, out, b - 1);
            }
            else
                left->best(n, out, b - 1);
        }
        else {
            if(left && left->cnt > 0)
                left->best(n, out, b - 1);
            else {
                out |= (1 << b);
                right->best(n, out, b - 1);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    btrie trie;
    trie.add(0);
    int q;
    cin >> q;
    while(q--) {
        char t;
        int n;
        cin >> t >> n;
        if(t == '+')
            trie.add(n);
        if(t == '-')
            trie.rem(n);
        if(t == '?') {
            int o = 0;
            trie.best(~n, o);
            cout << (n^o) << endl;
        }
    }
}