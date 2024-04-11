#include <bits/stdc++.h>
using namespace std;
#define mod 1000003

#define N 210
typedef vector<int> vi;
int n;

int A[N];

vi multi(vi a, vi b) {
    vi c;
    int la = a.size();
    int lb = b.size();
    c.resize(la + lb);
    for(int i = 0; i < c.size(); i ++) c[i] = 0;
    for(int i = 0; i < la; i ++) for(int j = 0; j < lb; j ++) {
        c[i + j] += 1ll * a[i] * b[j] % mod;
        if(c[i + j] >= mod) c[i + j] -= mod;
    }
    return c;
}

void div(vi &c) {
    int a = c.size();
    for(int i = a - 1; i >= n; i --) {
        int x = c[i];
        for(int j = 0; j <= n; j ++) {
            int k = i - n + j;
            c[k] -= 1ll * x * A[j] % mod;
            if(c[k] < 0) c[k] += mod;
        }
    }
    c.resize(n);
}

vi calc(int m) {
    if(m < n) {
        vi v;
        v.resize(n);
        for(int i = 0; i < n; i ++) v[i] = 0;
        v[m] = 1;
        return v;
    }
    vi a = calc(m / 2);
    vi b = multi(a, a);
    vi c;
    if(m & 1) {
        c.resize(b.size() + 1);
        for(int i = 0; i < b.size(); i ++) c[i + 1] = b[i];
        c[0] = 0;
    } else {
        c.resize(b.size());
        for(int i = 0; i < b.size(); i ++) c[i] = b[i];
    }
    div(c);
    return c;
}

int f[N], po[N];
int main() {
    //freopen("D3.in", "r", stdin);
    int C, W, H;
    scanf("%d%d%d", &C, &W, &H);
    po[0] = 1;
    for(int i = 1; i <= W; i ++) po[i] = po[i - 1] * H % mod;
    f[0] = 1;
    for(int i = 1; i <= W; i ++) {
        f[i] = 0;
        for(int j = 0; j < i; j ++) {
            f[i] += 1ll * po[j] * f[i - j - 1] % mod;
            if(f[i] >= mod) f[i] -= mod;
        }
        f[i] += 1ll * po[i];
        if(f[i] >= mod) f[i] -= mod;
    }
    A[W + 1] = 1;
    for(int i = 0; i <= W; i ++) A[W - i] = mod - po[i];
    n = W + 1;
    vi v = calc(C);
    int ans = 0;
    for(int i = 0; i <= W; i ++) {
        ans += 1ll * f[i] * v[i] % mod;
        if(ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
}