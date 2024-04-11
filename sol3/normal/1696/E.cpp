#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

const long long mod = 1000000007;
long long fac[600005], ifac[600005];
int a[200005], n;

inline void Read() {
    n = qread();
    for (int i = 0;i <= n;i++) a[i] = qread();
}

inline void Prefix() {
    ifac[1] = 1;
    for (int i = 2;i <= 600000;i++) ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
    fac[0] = fac[1] = ifac[0] = 1;
    for (int i = 2;i <= 600000;i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * ifac[i] % mod;
    }
}

inline long long C(int n, int r) {
    if (n < r || r < 0) return 0;
    return fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}

inline void Solve() {
    long long ans = 0;
    for (int i = 0;i <= n;i++) ans = (ans + C(a[i] + i, i + 1)) % mod;
    cout << ans << endl;
}

int main() {
    Read();
    Prefix();
    Solve();
    return 0;
}