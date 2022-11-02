#include<bits/stdc++.h>
using namespace std;

#define M 200010
#define N 2010

const int mod = 1e9 + 7;

int powmod(int x, int y) {
    int ret = 1;
    while(y) {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int fac[M], rfac[M];

void prepare() {
    fac[0] = 1;
    for(int i = 1; i < M; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    rfac[M-1] = powmod(fac[M-1], mod - 2);
    for(int i = M-1; i; i --) rfac[i-1] = 1ll * rfac[i] * i % mod;
}

int c(int n, int m) {
    return 1ll * rfac[m] * rfac[n-m] % mod * fac[n] % mod;
}

struct pnt {
    int x, y;
    void in() {scanf("%d%d", &x, &y);}
    bool operator < (const pnt &a) const {
        return x==a.x?y<a.y:x<a.x;
    }
    bool operator == (const pnt &a) const {
        return x == a.x && y == a.y;
    }
    int dist() {return x + y;}
} r[N];

int dp[N];

int main() {
    prepare();
    int h, w, n, ans;
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 1; i <= n; i ++) r[i].in();
    sort(r + 1, r + n + 1);
    n = unique(r + 1, r + n + 1) - r - 1;
    ans = c(h + w - 2, h - 1);
    for(int i = 1; i <= n; i ++) {
        dp[i] = c(r[i].x+r[i].y-2, r[i].x-1);
        for(int j = 1; j < i; j ++) {
            if(r[j].x <= r[i].x && r[j].y <= r[i].y) {
                dp[i] -= 1ll * dp[j] * c(r[i].dist() - r[j].dist(), r[i].x - r[j].x) % mod;
                if(dp[i] < 0) dp[i] += mod;
            }
        }
        ans -= 1ll * dp[i] * c(h+w-r[i].dist(), h-r[i].x) % mod;
        if(ans < 0) ans += mod;
    }
    printf("%d\n", ans);
}