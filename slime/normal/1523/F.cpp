#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 120;
int x[maxn], y[maxn], t[maxn];
ll di(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int dp[1 << 14][105];
ll tt[1 << 14][105];
ll dis[1 << 14][120];
int n, m;
void upd(int tp) {
    for (int i = 1; i < (1 << n); i++)
        for (int j = 0; j < n; j++) 
            if (!(i & (1 << j)))
                chkmin(tt[i ^ (1 << j)][tp], tt[i][tp] + dis[i][j]);
}
int fl[105];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
 
    for (int j = 0; j < m; j++)
        cin >> x[j + n] >> y[j + n] >> t[j];
 
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n + m; j++) {
            dis[i][j] = 2e9;
            for (int k = 0; k < n; k++)
                if (i & (1 << k))
                    chkmin(dis[i][j], (ll)di(k, j));
        }
    
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j <= m; j++)
            tt[i][j] = 2e9;
    
    for (int i = 0; i < (1 << n); i++) 
        if (__builtin_popcount(i) <= 1) tt[i][0] = 0;
    
    upd(0);
    vector<pi> cr;
    for (int j = 0; j < m; j++)
        cr.pb(mp(t[j], j));
    sort(cr.begin(), cr.end());
 
    for (int i = 0; i < cr.size(); i++) {
        int id = cr[i].se;
        for (int j = 0; j < (1 << n); j++) {
            dp[j][id] = -1;
            if (j == 0) dp[j][id] = 1;
 
            for (int k = 0; k < i; k++) {
                int v = cr[k].se;
                if (dp[j][v] != -1 && di(n + id, n + v) <= t[id] - t[v])
                    chkmax(dp[j][id], dp[j][v] + 1);
            }
 
            for (int k = 0; k <= i; k++)
                if (dis[j][id + n] + tt[j][k] <= t[id])
                    chkmax(dp[j][id], k + 1);
        }
        memset(fl, 0, sizeof(fl));
        for (int j = 0; j < (1 << n); j++)
            if (dp[j][id] != -1) {
                int sz = dp[j][id];
                if (chkmin(tt[j][sz], (ll)t[id])) fl[sz] = 1;
                for (int s = 0; s < n; s++) {
                    if (j & (1 << s)) continue;
                    ll e = t[id] + di(id + n, s);
                    int er = j ^ (1 << s);
                    if (chkmin(tt[er][sz], e)) fl[sz] = 1;
                }
            }
        for (int j = 0; j <= m; j++)
            if (fl[j]) upd(j);
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j <= m; j++)
            if (tt[i][j] <= 1.8 * 1e9) chkmax(ans, j);
    cout << ans << endl;
    return 0;
}