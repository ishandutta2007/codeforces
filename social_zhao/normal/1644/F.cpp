#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 2e6 + 5, P = 998244353, sgn[] = { 1, -1 };
int n, k, f[N];
int fac[N], inv[N], pre[N];
int pri[N], tot, pw[N], vis[N];

int qpow(int x, int y) {
    int res = 1;
    while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
    return res;
}

void inc(int &x, int y) { x = (x + y) % P; }

void init(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
    inv[n] = qpow(fac[n], P - 2);
    for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
    pre[0] = 1;
    for(int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + sgn[i & 1] * inv[i]) % P;
}

int F(int n) { // \sum_{i=1^k} S(n, i)
    int lim = min(n, k);
    pw[0] = 0, pw[1] = 1;
    for(int i = 1; i <= lim; i++) vis[i] = 0; tot = 0;
    for(int i = 2; i <= lim; i++) {
        if(!vis[i]) pw[i] = qpow(i, n), pri[++tot] = i;
        for(int j = 1; j <= tot && i * pri[j] <= lim; j++) {
            vis[i * pri[j]] = 1, pw[i * pri[j]] = pw[i] * pw[pri[j]] % P;
            if(i % pri[j] == 0) break;
        }
    }
    int ans = 0;
    for(int t = 0; t <= lim; t++) inc(ans, pw[t] * inv[t] % P * pre[lim - t]);
    return ans;
}

void file() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
}

signed main() {
    n = get(), k = get();
    if(k == 1) return cout << 1 << endl, 0;
    init(n);
    for(int i = 1; i <= n; i++) f[i] = F((n + i - 1) / i);
    for(int i = n; i >= 1; i--) {
        for(int j = i + i; j <= n; j += i) f[i] = (f[i] - f[j]) % P;
        if(n % i) f[i] = (f[i] - 1) % P;
    }
    int res = f[1];
    res = (res % P + P) % P;
    printf("%lld\n", res);
    return 0;
}