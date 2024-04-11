#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

ll n, k;
vector<ll> adj[N];
ll s[N];

pair<ll, ll> dfs(ll u, ll k){
    // cout << "dfs(" << u << " " << k << ")" << endl;

    pair<ll, ll> ans;
    ans.first = s[u] * k;
    ans.second = s[u] * (k + 1);

    if(adj[u].empty())
        return ans;

    if(adj[u].size() == 1){
        auto ans2 = dfs(adj[u][0], k);
        ans.first += ans2.first;
        ans.second += ans2.second;
        // cout << u << " -> " << ans.first << " " << ans.second << endl;
        return ans;
    }

    ll cnt = adj[u].size();
    vector<ll> v;
    ll sum = 0;
    for(int i = 0; i < cnt; ++i){
        auto ans2 = dfs(adj[u][i], k / cnt);
        v.push_back(ans2.second - ans2.first);
        sum += ans2.first;
    }
    sort(all(v), greater<ll>());

    ans.first += sum;
    ans.second += sum;

    for(int i = 0; i < k % cnt; ++i)
        ans.first += v[i];

    for(int i = 0; i < k % cnt + 1; ++i)
        ans.second += v[i];

    // cout << u << " -> " << ans.first << " " << ans.second << endl;
    return ans;
}

void solve(){
    cin >> n >> k;
    fill(adj, adj + n + 1, vector<ll>());

    for(int i = 2; i <= n; ++i){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for(int i = 1; i <= n; ++i)
        cin >> s[i];

    cout << dfs(1, k).first << "\n";
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