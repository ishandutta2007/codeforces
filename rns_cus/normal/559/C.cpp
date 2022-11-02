#include <bits/stdc++.h>
using namespace std;

struct pnt{
    int x, y;
    pnt(int x = 0, int y = 0):x(x), y(y){}
};

bool operator < (pnt a, pnt b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int po(int x, int y, int mo) {
    int rlt = 1;
    while(y) {
        if(y & 1) rlt = 1ll * rlt * x % mo;
        y >>= 1;
        x = 1ll * x * x % mo;
    }
    return rlt;
}
#define N 301000
int f[N], g[N];
#define mod 1000000007
pnt p[N];
int ans[N];

int Calc(int x, int y) {
    return 1ll * f[x + y] * g[x] % mod * g[y] % mod;
}

int main() {
    //freopen("1.in", "r", stdin);
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    f[0] = 1;
    g[0] = 1;
    int m = w + h;
    for(int i = 1; i <= m; i ++) f[i] = 1ll * f[i - 1] * i % mod;
    g[m] = po(f[m], mod - 2, mod);
    for(int i = m - 1; i; i --) g[i] = 1ll * g[i + 1] * (i + 1) % mod;
    p[0] = pnt(1, 1);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
    p[n + 1] = pnt(w, h);
    sort(p + 1, p + n + 2);
    ans[0] = 1;
    for(int i = 1; i <= n + 1; i ++) {
        ans[i] = Calc(p[i].x - 1, p[i].y - 1);
        for(int j = 1; j < i; j ++) if(p[j].x <= p[i].x && p[j].y <= p[i].y) {
            ans[i] = ans[i] - (1ll * Calc(p[i].x - p[j].x, p[i].y - p[j].y) * ans[j] % mod);
            if(ans[i] < 0) ans[i] += mod;
        }
    }
    printf("%d\n", ans[n + 1]);
    return 0;

}