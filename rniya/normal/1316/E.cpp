#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,p,k; cin >> n >> p >> k;
    vector<pair<ll,int>> A;
    for (int i=0;i<n;++i){
        ll a; cin >> a;
        A.emplace_back(a,i);
    }
    sort(A.begin(),A.end()); reverse(A.begin(),A.end());
    vector<vector<ll>> s(n,vector<ll>(p));
    for (int i=0;i<n;++i)
        for (int j=0;j<p;++j)
            cin >> s[i][j];
    vector<vector<ll>> dp(2,vector<ll>(1<<p,-1));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        for (int mask=0;mask<(1<<p);++mask){
            if (dp[i&1][mask]==-1) continue;
            int cnt=p;
            for (int j=0;j<p;++j) if (!(mask&1<<j)){
                dp[(i&1)^1][mask|1<<j]=max(dp[(i&1)^1][mask|1<<j],dp[i&1][mask]+s[A[i].second][j]);
                --cnt;
            }
            if (i-cnt<k) dp[(i&1)^1][mask]=max(dp[(i&1)^1][mask],dp[i&1][mask]+A[i].first);
            else dp[(i&1)^1][mask]=max(dp[(i&1)^1][mask],dp[i&1][mask]);
            dp[i&1][mask]=0;
        }
    }
    cout << dp[n&1][(1<<p)-1] << '\n';
}