#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()


int n;
ll k;
vector<ll> s;
vector<int> p;
vector<vector<int>> g;
vector<vector<ll>> dp;


void dfs(int v, ll l, ll r){
    dp[v].assign(r - l, 0);
    if(g[v].size() == 0){
        for(int i = l; i < r; i += 1){
            dp[v][i - l] = s[v] * i;
        }
        return;
    }
    int sns = g[v].size();
    ll sl = floor((long double)(l) / sns);
    ll sr = ceil((long double)(r - 1) / sns) + 3;
    if(sns == 1){
        sl = l;
        sr = r;
    }
    for(auto to: g[v]){
        dfs(to, sl, sr);
    }
    for(ll mc = l; mc < r; mc += 1){
        dp[v][mc - l] += s[v] * mc;
        ll sc = mc / sns;
        vector<ll> f;
        for(auto to: g[v]){
            dp[v][mc - l] += dp[to][sc - sl];
            f.push_back(dp[to][sc + 1 - sl] - dp[to][sc - sl]);
        }
        sort(rall(f));
        for(ll x = 0; x < mc - sc * sns; x += 1){
            dp[v][mc - l] += f[x];
        }
    }
}


ll solve(){
    dp.assign(n, vector<ll>());
    dfs(0, k, k + 1);
    return dp[0][0];
}


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        s.resize(n);
        p.resize(n);
        g.assign(n, vector<int>());
        p[0] = -1;
        for(int i = 1; i < n; i += 1){
            cin >> p[i];
            --p[i];
            g[p[i]].push_back(i);
        }
        for(int i = 0; i < n; i += 1){
            cin >> s[i];
        }
        cout << solve() << "\n";
    }
    return 0;
}