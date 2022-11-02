#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

#define N 500010

ll c[N];

struct edge {
    int x, y;
    void in() {scanf("%d%d", &x, &y);}
    bool operator < (const edge &e) const {return (c[x]^c[y]) < (c[e.x]^c[e.y]);}
    bool operator == (const edge &e) const {return (c[x]^c[y]) == (c[e.x]^c[e.y]);}
    bool operator != (const edge &e) const {return (c[x]^c[y]) != (c[e.x]^c[e.y]);}
} e[N];

int p[N];
int find_rt(int x) {return x == p[x] ? x : p[x] = find_rt(p[x]);}

int pw[N];

int main() {
    pw[0] = 1;
    for(int i = 1; i < N; i ++) pw[i] = 2*pw[i-1]%mod;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++) scanf("%I64d", &c[i]);
    for(int i = 1; i <= m; i ++) e[i].in();
    sort(e + 1, e + m + 1);
    if(m == 0) {
        printf("%d\n", 1ll * pw[n] * pw[k] % mod);
        return 0;
    }
    for(int i = 1; i <= n; i ++) p[i] = i;
    p[e[1].x] = e[1].y;
    int com = n - 1, ans = 0, cnt = 1;
    for(int i = 2; i <= m; i ++) {
        if(e[i] != e[i-1]) {
            ans += pw[com];
            if(ans >= mod) ans -= mod;
            for(int j = i-1; j && e[j] == e[i-1]; j --) p[e[j].x] = e[j].x, p[e[j].y] = e[j].y;
            com = n;
            cnt ++;
        }
        int xx = find_rt(e[i].x), yy = find_rt(e[i].y);
        if(xx != yy) {
            p[xx] = yy;
            com --;
        }
    }
    ans += pw[com];
    if(ans >= mod) ans -= mod;
    ans = (ans + 1ll * (pw[k]-cnt+mod) * pw[n]) % mod;
    printf("%d\n", ans);
}