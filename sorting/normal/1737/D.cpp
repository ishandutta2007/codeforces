#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll M = 25e4 + 3;
const ll N = 500 + 3;

ll n, m;
vector<pair<ll, ll>> adj[N];
ll d[N][N];

void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        adj[i].clear();

    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            d[i][j] = N + 1;

    vector<array<ll, 3>> edges;
    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
        d[u][v] = 1;
        d[v][u] = 1;
    }

    for(ll i = 1; i <= n; ++i)
        d[i][i] = 0;

    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            for(ll k = 1; k <= n; ++k){
                if(d[j][i] + d[i][k] < d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }

    static ll dp[N];
    fill(dp, dp + n + 1, 4 * N);
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j)
            check_min(dp[i], d[i][j] + d[j][1] + d[j][n] + 2);
    }

    ll ans = LLONG_MAX;
    for(ll i = 0; i < m; ++i){
        auto [u, v, w] = edges[i];
        ll mn = d[1][u] + d[n][v] + 1;
        check_min(mn, (ll)d[1][v] + d[n][u] + 1);
        check_min(mn, (ll)dp[u]);
        check_min(mn, (ll)dp[v]);
        
        check_min(ans, (ll)w * mn);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    
    while(t--){
        solve();
    }
}