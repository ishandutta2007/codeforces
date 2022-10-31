#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


#define ll long long


const ll inf = 2e18;
const ll mod = 998244353;


int n, m;
int d;
vector<ll> a;
vector<vector<int>> g;
vector<int> s;
vector<ll> cnt;
vector<vector<int>> dp;
vector<int> usd;


void dfs(ll v){
    usd[v] = 1;
    cnt[v] = a[v] % mod;
    for(int i = 0; i < a[v] && i < d; i += 1){
        dp[v][i] = 1;
    }
    for(auto to: g[v]){
        if(!usd[to]){
            dfs(to);
        }
        cnt[v] = (cnt[v] + cnt[to]) % mod;
        ll f = 0;
        for(int i = 0; i + 1 < d; i += 1){
            if(dp[to][i] == 1){
                f += 1;
            }
            if(f > 0 && dp[v][i + 1] == 0){
                f -= 1;
                dp[v][i + 1] = 1;
            }
        }
        if(dp[to][d - 1] == 1){
            dp[v][d - 1] = 1;
        }
    }
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
        cin >> n >> m;
        a.resize(n);
        for(int i = 0; i < n; i += 1){
            cin >> a[i];
        }
        s.assign(n, 0);
        g.assign(n, vector<int>());
        for(int i = 0; i < m; i += 1){
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            s[x] += 1;
            g[y].push_back(x);
        }
        int rt = -1;
        for(int i = 0; i < n; i += 1){
            if(s[i] == 0){
                rt = i;
            }
        }
        usd.assign(n, 0);
        d = n + 10;
        dp.assign(n, vector<int>(d));
        cnt.resize(n);
        dfs(rt);
        int cntz = 0;
        int lst1 = 0;
        for(int i = 0; i < d; i += 1){
            if(dp[rt][i]){
                lst1 = i + 1;
            } else{
                cntz += 1;
            }
        }
        ll rs = 0;
        if(dp[rt][d - 1]){
            rs = (cnt[rt] + cntz) % mod;
        } else{
            rs = lst1;
        }
        cout << rs << "\n";
    }
    return 0;
}