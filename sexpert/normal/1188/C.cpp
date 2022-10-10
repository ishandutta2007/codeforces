#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
const ll MOD = 998244353;
ll dp[1005][1005], tot = 0;
int mn[1005], m, k;
vector<ii> wtf[100005];
 
void recalc() {
    dp[m - 1][1] = 1;
    dp[m - 1][0] = 1;
    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i + 1][j];
            if(j > 1) dp[i][j] += dp[mn[i]][j - 1];
            if(j == 1) dp[i][j]++;
            if(dp[i][j] > MOD) dp[i][j] -= MOD;
            if(i == m - 1)
                dp[i][j] = (j <= 1 ? 1 : 0);
            //cout << "dp(" << i << ", " << k << ") = " << dp[i][k] << endl;
        }
    }
    //cout << "Recalced uwu" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    m = a.size();
    for(int i = 0; i < m; i++) {
        mn[i] = i + 1;
        for(int j = i + 1; j < m; j++) {
            wtf[a[j] - a[i]].push_back({i, j});
        }
    }
    ll ans = 0;
    int cur = 0;
    recalc();
    tot = dp[0][k];
    for(auto p : wtf[0])
        mn[p.first] = p.second + 1;
    for(; cur <= 100001; cur++) {
        if(wtf[cur].empty()) continue;
        for(auto p : wtf[cur])
            mn[p.first] = p.second + 1;
        recalc();
        ll amt = (tot - dp[0][k])%MOD;
        ans = (ans + amt * (ll)cur) % MOD;
        tot = dp[0][k];
        if(dp[0][k] == 0) break;
    }
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}