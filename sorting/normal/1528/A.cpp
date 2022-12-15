#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 3;

int n, l[N], r[N];
pair<ll, bool> dp[N][2];
vector<int> adj[N];

ll solve(int u, bool is_r, int p = -1){
    auto &[ans, solved] = dp[u][is_r];
    if(solved) return ans;

    solved = true;
    ans = 0;

    ll curr = is_r ? r[u] : l[u];
    for(int to: adj[u])
        if(to != p){
            ans += max(abs(l[to] - curr) + solve(to, 0, u), abs(r[to] - curr) + solve(to, 1, u));
        }
    return ans;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    for(int i = 1; i <= n; ++i)
        adj[i].clear();

    for(int i = 1; i <= n; ++i)
        dp[i][0].second = dp[i][1].second = false;

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << max(solve(1, 0), solve(1, 1)) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}