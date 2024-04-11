#include <cctype>
#include <cstdio>
#include <vector>
#include <algorithm>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 3e5 + 5;

int n;
std::vector<int> a, b;

struct SegmentTree {
    int f[N << 2];

    inline void pushUp(int u) {
        f[u] = std::min(f[u << 1], f[u << 1 | 1]);
    }
    void modify(int u, int l, int r, int p, int x) {
        if (l == r) { f[u] = x; return; }
        int mid = l + r >> 1;
        if (p <= mid) { modify(u << 1, l, mid, p, x); }
        else { modify(u << 1 | 1, mid + 1, r, p, x); }
        pushUp(u);
    }
    int query(int u, int l, int r, int pl, int pr) {
        if (pl > pr) { return 1e9; }
        if (l == pl && r == pr) { return f[u]; }
        int mid = l + r >> 1;
        if (pr <= mid) { return query(u << 1, l, mid, pl, pr); }
        else if (pl > mid) { return query(u << 1 | 1, mid + 1, r, pl, pr); }
        else { return std::min(query(u << 1, l, mid, pl, mid), query(u << 1 | 1, mid + 1, r, mid + 1, pr)); }
    }
} smt;

std::vector<int> sort(std::vector<int> a) {
    std::sort(a.begin(), a.end()); return a;
}
std::vector<int> change(std::vector<int> a) {
    static std::vector<int> buc[N];
    for (int i = 0; i < n; i++) { buc[i].clear(); }
    for (int i = 0; i < n; i++) { buc[a[i]].push_back(i); }
    for (int i = 0, j = 0; i < n; i++) {
        for (auto u : buc[i]) { a[u] = j++; }
    }
    return a;
}
bool equal(std::vector<int> a, std::vector<int> b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) { return false; }
    } return true;
}

bool solve() {
    std::vector<int> p; p.resize(n);
    for (int i = 0; i < n; i++) {
        p[a[i]] = i;
        smt.modify(1, 0, n - 1, a[i], i);
    }
    for (int i = 0; i < n; i++) {
        int u = p[b[i]];
        if (smt.query(1, 0, n - 1, 0, b[i]) != u) { return false; }
        smt.modify(1, 0, n - 1, b[i], 1e9);
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); a.clear(); b.clear();
        for (int i = 0; i < n; i++) { a.push_back(read() - 1); }
        for (int i = 0; i < n; i++) { b.push_back(read() - 1); }
        if (equal(sort(a), sort(b))) {
            a = change(a); b = change(b);
            printf("%s\n", solve() ? "YES" : "NO");
        } else { printf("NO\n"); }
    }
    return 0;
}