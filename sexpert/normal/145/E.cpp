#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int l, r, c4, c7, c47, c74, toggle;
    node *left, *right;
    int getc4() { return toggle ? c7 : c4; }
    int getc7() { return toggle ? c4 : c7; }
    int getc47() { return toggle ? c74 : c47; }
    int getc74() { return toggle ? c47 : c74; }
    void merge() {
        c4 = left->getc4() + right->getc4();
        c7 = left->getc7() + right->getc7();
        c47 = max({left->getc47() + right->getc7(), left->getc4() + right->getc47(), left->getc4() + right->getc7()});
        c74 = max({left->getc74() + right->getc4(), left->getc7() + right->getc74(), left->getc7() + right->getc4()});
    }
    void push() {
        left->toggle ^= toggle;
        right->toggle ^= toggle;
        toggle = 0;
    }

    node(int l, int r, string &s) : l(l), r(r), toggle(0){
        if(l == r) {
            c4 = s[l] == '4';
            c7 = 1 - c4;
            c47 = c74 = 1;
        }
        else {
            int m = (l + r)/2;
            left = new node(l, m, s);
            right = new node(m + 1, r, s);
            merge();
        }
    }

    void upd(int rl, int rr) {
        if(rr < l || r < rl)
            return;
        if(rl <= l && r <= rr) {
            toggle ^= 1;
            return;
        }
        push();
        left->upd(rl, rr);
        right->upd(rl, rr);
        merge();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    node tree(0, n - 1, s);
    while(m--) {
        string q;
        cin >> q;
        if(q == "count")
            cout << tree.getc47() << '\n';
        else {
            int l, r;
            cin >> l >> r;
            tree.upd(l - 1, r - 1);
        }
    }
}