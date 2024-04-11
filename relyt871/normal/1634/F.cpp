#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
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

namespace ModCalculator {
    int MOD;
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

int n, q, fib[MAXN], ans;
int a[MAXN], b[MAXN];

inline void Upd(int x, int v, int flag) {
    if (x > n) return;
    ans -= (b[x] > 0);
    (flag > 0)? Inc(b[x], v) : Dec(b[x], v);
    ans += (b[x] > 0);
}

void solve() {
    read(n); read(q); read(MOD);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = Add(fib[i - 1], fib[i - 2]);
    }
    for (int i = 1; i <= n; ++i) {
         read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        Dec(a[i], b[i]);
    }
    b[1] = a[1];
    ans = (b[1] > 0);
    for (int i = 2; i <= n; ++i) {
        b[i] = Sub(a[i], Add(a[i - 1], a[i - 2]));
        ans += (b[i] > 0);
    }

    char cmd[10];
    int l, r;
    while (q--) {
        scanf("%s", cmd);
        read(l); read(r);
        if (cmd[0] == 'A') {
            Upd(l, 1, 1);
            Upd(r + 1, fib[r - l + 2], -1);
            Upd(r + 2, fib[r - l + 1], -1);
        } else {
            Upd(l, 1, -1);
            Upd(r + 1, fib[r - l + 2], 1);
            Upd(r + 2, fib[r - l + 1], 1);
        }
        puts(ans? "NO" : "YES");
    }
}

int main() {
    solve();
    return 0;
}