#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;
const int N = 1000 + 3;

int n, m;
ll a[N], in[N], out[N];
vector<int> adj[N], r_adj[N];
vector<int> order;
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(int to: adj[u]){
        if(vis[to])
            continue;
        dfs(to);
    }
    order.push_back(u);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        r_adj[i].clear();
        in[i] = 0;
        out[i] = 0;
    }

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        // cout << i << " i" << endl;
        static ll b[N];
        int cnt_nz = 0;
        for(int j = 1; j <= n; ++j){
            b[j] = a[j];
            cnt_nz += !!a[j];
        }
        // cout << cnt_nz << endl;
        if(!cnt_nz)
            break;
        ++ans;
        for(int j = 1; j <= n; ++j){
            for(int prev: r_adj[j])
                if(b[prev])
                    a[j]++;
            if(b[j])
                a[j]--;
        }
    }

    for(int i = 1; i <= n; ++i)
        vis[i] = false;

    order.clear();
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs(i);
    }

    reverse(all(order));

    for(int x: order){
        for(int to: adj[x]){
            a[to] += a[x];
            a[to] %= MOD;
        }
    }

    ans += a[order.back()];
    ans %= MOD;

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
}