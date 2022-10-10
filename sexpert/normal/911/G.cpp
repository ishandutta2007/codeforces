#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int A[MAXN];

struct node {
    int l, r;
    vector<int> f;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        f.reserve(101);
        for(int i = 1; i <= 100; i++)
            f[i] = i;
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void compose(const vector<int> &g) {
        for(int i = 1; i <= 100; i++) {
            f[i] = g[f[i]];
        }
    }

    void compose(int x, int y) {
        for(int i = 1; i <= 100; i++) {
            if(f[i] == x)
                f[i] = y;
        }
    }

    void restore() {
        for(int i = 1; i <= 100; i++)
            f[i] = i;
    }

    void update(int le, int ri, int x, int y) {
        if(l > ri || r < le)
            return;

        if(le <= l && r <= ri) {
            compose(x, y);
            return;
        }
        left->compose(f);
        right->compose(f);
        restore();
        left->update(le, ri, x, y);
        right->update(le, ri, x, y);
    }

    void ans() {
        if(l == r) {
            cout << f[A[l]] << " ";
            return;
        }
        left->compose(f);
        right->compose(f);
        left->ans();
        right->ans();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    node segtree(1, n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        segtree.update(l, r, x, y);
    }
    segtree.ans();
    cout << endl;
}