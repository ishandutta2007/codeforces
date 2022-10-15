#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

typedef std::vector<std::pair<int, int>> vector;

const int N = 1e6 + 5;

int n, p, q, k, a[N];

vector operator +(vector f, vector g) {
    for (auto &x : g) {
        for (int i = 0; i < f.size(); i++) {
            if (f[i].second == x.second) {
                f[i].first += x.first;
                x.first = 0;
            }
        }
    }
    for (auto x : g) {
        if (x.first != 0) { f.push_back(x); }
    }
    std::sort(f.begin(), f.end());
    std::reverse(f.begin(), f.end());
    for (; f.size() >= k; f.pop_back()) {
        for (int i = (int) f.size() - k; i < f.size(); i++) {
            f[i].first -= f.back().first;
        }
    }
    for (; !f.empty() && f.back().first == 0; f.pop_back());
    return f;
}

struct SegmentTree {
    vector f[N];
    int tag[N], len[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = f[ls] + f[rs];
    }
    inline void pushTag(int u, int x) {
        f[u] = vector (1, {len[u], x});
        tag[u] = x;
    }
    inline void pushDown(int u) {
        if (tag[u] == -1) { return; }
        int ls = u << 1, rs = ls | 1;
        pushTag(ls, tag[u]); pushTag(rs, tag[u]);
        tag[u] = -1;
    }
    
    void build(int u, int l, int r) {
        len[u] = r - l; tag[u] = -1;
        if (l + 1 >= r) { pushTag(u, a[l]); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, x); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, vector &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res = res + f[u]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); q = read(); p = read(); k = 100 / p + 1;
    for (int i = 0; i < n; i++) { a[i] = read(); }
    smt.build(1, 0, n);
    for (int i = 0; i < q; i++) {
        int opt = read();
        if (opt == 1) {
            int l = read(), r = read(), x = read(); l--;
            smt.modify(1, 0, n, l, r, x);
        } else {
            int l = read(), r = read(); l--;
            vector ans;
            smt.query(1, 0, n, l, r, ans);
            printf("%d", ans.size());
            for (auto x : ans) { printf(" %d", x.second); }
            printf("\n");
        }
    }
    return 0;
}