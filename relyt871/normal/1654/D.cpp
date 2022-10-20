#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

namespace ModCalculator {
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

inline void cmax(int &x, int y) {
    if (x < y) x = y;
}

int n, inv[MAXN], ans;
vector<pii> d[MAXN];
int cnt[MAXN], mx[MAXN];

void prework() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = Mul(MOD - MOD / i, inv[MOD % i]);
    }
    for (int i = 2; i < MAXN; ++i) {
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j) continue;
            int c = 0;
            while (x % j == 0) {
                ++c;
                x /= j;
            }
            d[i].push_back(make_pair(j, c));
        }
        if (x > 1) {
            d[i].push_back(make_pair(x, 1));
        }
    }
}

struct Edge {
    int v, x, y, nxt;
} e[MAXN << 1];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v, int x, int y) {
    e[++eCnt].v = v;
    e[eCnt].x = x;
    e[eCnt].y = y;
    e[eCnt].nxt = first[u];
    first[u] = eCnt;
}

void DFS(int u, int fa, int w) {
    Inc(ans, w);
    for (int i = first[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == fa) continue;
        for (auto pr : d[e[i].x]) {
            cnt[pr.first] -= pr.second;
        }
        for (auto pr : d[e[i].y]) {
            cnt[pr.first] += pr.second;
            cmax(mx[pr.first], cnt[pr.first]);
        }
        DFS(v, u, Mul(w, Mul(e[i].x, inv[e[i].y])));
        for (auto pr : d[e[i].x]) {
            cnt[pr.first] += pr.second;
        }
        for (auto pr : d[e[i].y]) {
            cnt[pr.first] -= pr.second;
        }
    }
}

void solve() {
    read(n);
    eCnt = 0;
    for (int i = 1; i <= n; ++i) {
        first[i] = cnt[i] = mx[i] = 0;
    }
    for (int i = 1, u, v, x, y; i < n; ++i) {
        read(u); read(v); read(x); read(y);
        int d = __gcd(x, y);
        x /= d; y /= d;
        AddEdge(u, v, y, x);
        AddEdge(v, u, x, y);
    }
    ans = 0;
    DFS(1, 0, 1);
    for (int i = 1; i <= n; ++i) {
        if (mx[i]) {
            ans = Mul(ans, Ksm(i, mx[i]));
        }
    }
    printf("%d\n", ans);
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}