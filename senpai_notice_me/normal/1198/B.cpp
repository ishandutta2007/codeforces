#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2e5 + 5;

int n, a[MAXN];

namespace SegTree {
    int val[MAXN << 2];

    void build(int k, int l, int r) {
        val[k] = -1;
        if (l == r) {
            val[k] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
    }
    
    void down(int k) {
        if (val[k] != -1) {
            val[k << 1] = max(val[k << 1], val[k]);
            val[k << 1 | 1] = max(val[k << 1 | 1], val[k]);
            val[k] = -1;
        }
    }
    
    void opt1(int k, int l, int r, int pos, int v) {
        if (l == r) {
            val[k] = v;
            return;
        }
        down(k);
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            opt1(k << 1, l, mid, pos, v);
        } else {
            opt1(k << 1 | 1, mid + 1, r, pos, v);
        }
    }
    
    int query(int k, int l, int r, int pos) {
        if (l == r) {
            return val[k];
        }
        down(k);
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            return query(k << 1, l, mid, pos);
        } else {
            return query(k << 1 | 1, mid + 1, r, pos);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    
    SegTree::build(1, 1, n);
    
    int m; scanf("%d", &m);
    while (m--) {
        int opt; scanf("%d", &opt);
        if (opt == 1) {
            int p, x; scanf("%d%d", &p, &x);
            SegTree::opt1(1, 1, n, p, x);
        } else {
            int x; scanf("%d", &x);
            SegTree::val[1] = max(SegTree::val[1], x);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", SegTree::query(1, 1, n, i), " \n"[i == n]);
    }
    
    return 0;
}