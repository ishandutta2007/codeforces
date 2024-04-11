#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n;
long long ans;
bool used[N];
std::vector<int> x, y, p;

struct FenwickTree {
    long long f[N];

    inline void modify(int u, int x) {
        for (u++; u <= n; u += u & -u) { f[u] += x; }
    }
    inline long long query(int u) {
        int res = 1;
        for (u++; u; u ^= u & -u) { res += f[u]; } return res;
    }
    inline long long query(int l, int r) { return query(r) - query(l - 1); }
} bit;

bool compare(int u, int v) {
    return y[u] == y[v] ? x[u] < x[v] : y[u] > y[v];
}

void change(std::vector<int> &vec) {
    std::vector<int> tb = vec;
    std::sort(tb.begin(), tb.end());
    for (int i = 0; i < n; i++) {
        vec[i] = std::lower_bound(tb.begin(), tb.end(), vec[i]) - tb.begin();
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        x.push_back(read()); y.push_back(read()); p.push_back(i);
    }
    change(x); change(y);
    std::sort(p.begin(), p.end(), compare);
    for (int i = 0, j = 0; i < n; i++) {
        for (; j < n && y[p[i]] == y[p[j]]; j++) {
            if (!used[x[p[j]]]) {
                used[x[p[j]]] = true;
                bit.modify(x[p[j]], 1);
            }
        }
        if (i && y[p[i - 1]] == y[p[i]]) {
            ans += bit.query(x[p[i - 1]] + 1, x[p[i]]) * bit.query(x[p[i]], n - 1);
        } else {
            ans += bit.query(0, x[p[i]]) * bit.query(x[p[i]], n - 1);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}