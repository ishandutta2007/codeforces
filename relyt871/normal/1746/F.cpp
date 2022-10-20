#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 300005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

mt19937 Rand((unsigned)time(NULL));

int n, q, a[MAXN], val[MAXN << 1][31], ID;
map<int, int> id;

struct BIT {
    LL tr[MAXN];
    inline void add(int x, LL v) {
        for (; x <= n; x += (x & (-x))) {
            tr[x] += v;
        }
    }
    inline LL sum(int x) {
        LL ret = 0;
        for (; x; x -= (x & (-x))) {
            ret += tr[x];
        }
        return ret;
    }
    inline LL qry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} bit[31];

inline int GetID(int x) {
    if (x == 0) return 0;
    if (id.count(x)) return id[x];
    id[x] = ++ID;
    for (int i = 0; i <= 30; ++i) {
        val[ID][i] = Rand() % 1000000000 + 1;
    }
    return ID;
}

void Update(int p, int x) {
    x = GetID(x);
    for (int i = 0; i <= 30; ++i) {
        bit[i].add(p, val[x][i] - val[a[p]][i]);
    }
    a[p] = x;
}

bool Query(int l, int r, int k) {
    for (int i = 0; i <= 30; ++i) {
        if (bit[i].qry(l, r) % k) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    read(n); read(q);
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        Update(i, x);
    }
    while (q--) {
        int op, l, r, k;
        read(op); read(l); read(r);
        if (op == 1) {
            Update(l, r);
        } else {
            read(k);
            puts(Query(l, r, k)? "YES" : "NO");
        }
    }
}

int main() {
    solve();
    return 0;
}