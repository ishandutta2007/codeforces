#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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
    const int MOD = 1e9 + 7;
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

int gcd(int x, int y) {
    return (y == 0)? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return 1LL * x / gcd(x, y) * y % MOD;
}

int n, pr[MAXN], pcnt, vis[MAXN], phi[MAXN];
vector<int> d[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            d[j].push_back(i);
        }
    }
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pr[++pcnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pcnt && i * pr[j] <= n; ++j) {
            vis[i * pr[j]] = 1;
            if (i % pr[j]) {
                phi[i * pr[j]] = phi[i] * (pr[j] - 1);
            } else {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
        }
    }
    int ans = 0;
    for (int c = 1; c <= n - 2; ++c) {
        for (auto x : d[n - c]) {
            Inc(ans, Mul(lcm(c, x), phi[(n - c) / x]));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}