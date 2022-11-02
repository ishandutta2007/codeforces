#include<bits/stdc++.h>
using namespace std;

#define N 1010
#define M 105
const int mod = 1e9 + 7;

int invmod(int a,int m){int r,q,x=1,t=0;while(m!=0)r=a%m,q=a/m,a=m,m=r,r=x,x=t,t=r-t*q;return x;}

struct modint{
    int a;
    void operator = (const int &x) {a = (x % mod + mod) % mod;}
    bool operator ==(const int &x) {return a == x;}
    modint operator + (const modint &x) const {
        modint ret;
        ret.a = (a + x.a) % mod;
        return ret;
    }
    void operator += (modint x) {a = (a + x.a) % mod;}
    modint operator - (const modint &x) const {
        modint ret;
        ret.a = (a - x.a + mod) % mod;
        return ret;
    }
    void operator -= (modint x) {a = (a - x.a + mod) % mod;}
    modint operator * (const modint &x) const {
        modint ret;
        ret.a = int(1ll * a * x.a % mod);
        return ret;
    }
    modint operator * (const int &x) const {
        modint ret;
        ret.a = int((1ll * a * x % mod + mod) % mod);
        return ret;
    }
    void operator *= (modint x) {a = int((1ll * a * x.a % mod + mod) % mod);}
    void out() {printf("%d\n", (a + mod) % mod);}
} c[N][N], dp[M][N], f[N], inv[N], cont;

void build() {
    int i, j;
    for(i = 0; i < N; i ++) c[i][0] = 1;
    for(i = 1; i < N; i ++) c[0][i] = 0;
    for(i = 1; i < N; i ++) for(j = 1; j < N; j ++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    f[0] = 1;
    for(i = 1; i < N; i ++) f[i] = f[i - 1] * i;
    inv[N - 1] = invmod(f[N - 1].a, mod);
    for(i = N - 1; i; i --) inv[i - 1] = inv[i] * i;
}

int y[M], x[M];

int main() {
    int i, j, k, t, n, g;
    build();
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%d", x + i);
    for(i = 1; i <= n; i ++) scanf("%d", y + i);
    for(i = 0; i <= x[1]; i ++) dp[1][i] = c[x[1]][i];
    for(i = 2, g = x[1]; i <= n; i ++) {
        for(j=0;j<=g;j++)for(t=0;t<=x[i];t++)for(k=0;k<=y[i]-t;k++)dp[i][j+t+k]+=c[x[i]][t]*c[g-j][k]*dp[i-1][j];
        g += x[i];
    }
    cont = f[g];
    for(i = 1; i <= n; i ++) cont *= inv[x[i]];
    (cont * dp[n][g]).out();
}