#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int x, int y) {
    int r = 1;
    for(; y; y>>=1, x=1ll*x*x%mod) if(y&1) r = 1ll*r*x%mod;
    return r;
}

#define N 100010

int l[N], r[N], L[N], R[N], p[N<<2];
int dp[N<<2][3], x[N<<2], y[N<<2], a[N<<2], b[N<<2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    int M = 0;
    p[++ M] = 1;
    for(int i = 1; i <= n; i ++) {
        cin >> l[i] >> r[i];;
        p[++ M] = l[i];
        p[++ M] = ++ r[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> L[i] >> R[i];
        p[++ M] = L[i];
        p[++ M] = ++ R[i];
    }
    p[++ M] = k+1;
    sort(p+1, p+M+1);
    M = unique(p+1, p+M+1) - p-1;
    for(int i = 1; i <= n; i ++) {
        l[i] = lower_bound(p+1, p+M+1, l[i]) - p;
        r[i] = lower_bound(p+1, p+M+1, r[i]) - p;
    }
    for(int i = 1; i <= m; i ++) {
        L[i] = lower_bound(p+1, p+M+1, L[i]) - p;
        R[i] = lower_bound(p+1, p+M+1, R[i]) - p;
    }
    for(int i = 1; i <= n; i ++) x[r[i]-1] = max(x[r[i]-1], l[i]);
    for(int i = 1; i <= m; i ++) y[R[i]-1] = max(y[R[i]-1], L[i]);
    for(int i = 1; i < M; i ++) x[i] = max(x[i], x[i-1]), y[i] = max(y[i], y[i-1]);
    dp[0][2] = a[0] = b[0] = 1;
    for(int i = 1; i < M; i ++) {
        int c = (expmod(2, p[i+1]-p[i]) + mod - 2) % mod;
        dp[i][2] = (1ll*dp[i-1][0]+1ll*dp[i-1][1]+1ll*dp[i-1][2]) * c % mod;
        dp[i][1] = b[i-1] - (y[i]==0?0:b[y[i]-1]);
        if(dp[i][1] < 0) dp[i][1] += mod;
        dp[i][0] = a[i-1] - (x[i]==0?0:a[x[i]-1]);
        if(dp[i][0] < 0) dp[i][0] += mod;
        a[i] = (1ll*a[i-1] + 1ll*dp[i][1] + 1ll*dp[i][2]) % mod;
        b[i] = (1ll*b[i-1] + 1ll*dp[i][0] + 1ll*dp[i][2]) % mod;
    }
    int ans = (1ll*dp[M-1][0]+1ll*dp[M-1][1]+1ll*dp[M-1][2]) % mod;
    cout << ans << endl;
}