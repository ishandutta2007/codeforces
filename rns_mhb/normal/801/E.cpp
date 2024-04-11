#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
#define N 200010
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long bll;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}


int invmod(int a,int b,int m) {
    int d=__gcd(a,m);
    a/=d,b/=d,m/=d;
    int r,q,x=1,y=0,tmp=m;
    while(m)r=a%m,q=a/m,a=m,m=r,r=x,x=y,y=r-y*q;
    int ret=1ll*x*b%tmp;
    if(ret<0)ret+=tmp;
    return ret;
}

int k, p[10], c[20], d[20], b[N], m, sz, tot, ans[N], f[N];
bool vis[N];

void brute(int x, int y, int z) {
    if(x == m) {
        if(z > tot) {
            sz = y;
            tot = z;
            for(int i = 0; i <= y; i ++) c[i] = d[i];
        }
        return;
    }
    int w;
    for(int i = 1; i <= k; i ++) if((1ll * m) % (1ll * x * p[i]) == 0) {
        d[y + 1] = w = x * p[i];
        brute(w, y + 1, z + f[m / w] - b[w]);
    }
}

int main() {
    int n, i, a, t, j;
    f[1] = 1;
    f[2] = 1;
    for(i = 3; i < N; i ++) {
        a = sqrt(i);
        for(j = 2; j <= a; j ++) if(i % j == 0) {
            f[i] = __gcd(i / j, j) * f[i / j] * f[j] / f[__gcd(i / j, j)];
            break;
        }
        if(j > a) f[i] = i - 1;
    }
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 1) {printf("%d\n%d", 1, 0); return 0;}
    for(i = 1; i <= n; i ++) {
        scanf("%d", &a);
        j = __gcd(m, a);
        b[j] ++;
        vis[a] = 1;
    }
    for(i = 2, t = m; t > 1; i ++) if(t % i == 0) {
        p[++ k] = i;
        while(t % i == 0) t /= i;
    }
    d[0] = 1;
    brute(1, 0, f[m] - b[1]);
    for(i=0,t=0,ans[0]=1;i<=sz;i++)for(j=0;j<m;j++)if(__gcd(j, m)==c[i]&&!vis[j]) ans[++t] = j;
    for(i = t; i; i --) ans[i] = invmod(ans[i - 1], ans[i], m);
    printf("%d\n", tot);
    for(i = 1; i <= t; i ++) printf("%d ", ans[i]);
}