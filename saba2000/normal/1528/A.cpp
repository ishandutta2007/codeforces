#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[200009];
ll l[200009],r[200009];
ll dp[200009][2];
void dfs(ll x, ll p){
    dp[x][0] = 0;
    dp[x][1] = 0;
    for(ll y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        dp[x][0] += max(dp[y][0] + abs(l[y] - l[x]),
                        dp[y][1] + abs(r[y] - l[x]));
        dp[x][1] += max(dp[y][0] + abs(l[y] - r[x]),
                        dp[y][1] + abs(r[y] - r[x]));
    }
}
void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    for(ll i = 1; i < n; i++){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout << max(dp[1][0], dp[1][1]) << endl;
    for(ll i =1 ;i <= n; i++)
        v[i].clear();
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }

}