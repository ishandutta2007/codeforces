#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, q, a[N], p[N], ans[N];
std::vector<std::pair<int, int>> qry[N];

struct FenwickTree {
    int f[N];

    void modify(int u, int x) {
        for (; u <= n; u += u & -u) { f[u] += x; }
    }
    int query(int u) {
        int res = 0;
        for (; u >= 1; u ^= u & -u) { res += f[u]; }
        return res;
    }
} tr;

bool compare(int i, int j) {
    return a[i] == a[j] ? i < j : a[i] > a[j];
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); p[i] = i; }
    std::sort(p + 1, p + n + 1, compare);
    q = read();
    for (int i = 1; i <= q; i++) {
        int k = read(), pos = read();
        qry[k].push_back({pos, i});
    }
    for (int k = 1; k <= n; k++) {
        int i = p[k]; tr.modify(i, 1);
        for (auto tmp : qry[k]) {
            int x = tmp.first, res = -1;
            for (int l = 1, r = n, mid; l <= r; ) {
                mid = l + r >> 1;
                if (tr.query(mid) >= x) {
                    r = mid - 1; res = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[tmp.second] = a[res];
        }
    }
    for (int i = 1; i <= q; i++) { printf("%d\n", ans[i]); }
    return 0;
}