#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int powmod(int x, int y) {
    int ret = 1;
    while(y) {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

#define N 1000010

int fac[N], rfac[N];

int P(int n, int m) {return 1ll * fac[n] * rfac[m] % mod;}

int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    rfac[N-1] = powmod(fac[N-1], mod - 2);
    for(int i = N - 1; i; i --) rfac[i-1] = 1ll * rfac[i] * i % mod;
    int n;
    scanf("%d", &n);
    int ans = fac[n];
    for(int i = 1; i < n; i ++) ans = (ans + 1ll * P(n, i) * (fac[i] - 1)) % mod;
    printf("%d\n", ans);
}