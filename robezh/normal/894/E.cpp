#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, INF = (int)1e9;
typedef pair<int, int> P;
typedef long long ll;

int n, m, s;
ll psum[N];

struct edge {
    int to, cost;
};

ll get_sum(ll w) {
    ll l = 0, r = (ll)3e4, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(mid * (mid + 1) / 2 <= w) l = mid;
        else r = mid;
    }
    ll res = w * (l + 1) - psum[l];
    return res;
}

struct SCC {
    vector<edge> G[N], rG[N], cG[N];
    vector<int> vs;
    bool used[N];
    int cmp[N];
    int sc;
    ll sum[N], dp[N];

    void add_edge(int from, int to, int cost){
        G[from].push_back({to, cost});
        rG[to].push_back({from, cost});
    }

    void dfs(int v){
        used[v] = true;
        for(auto e : G[v]){
            if(!used[e.to]) dfs(e.to);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for(auto e : rG[v]){
            if(!used[e.to]) rdfs(e.to, k);
        }
    }

    int scc(){
        memset(used, 0, sizeof(used));
        vs.clear();
        for(int v = 0; v < n; v++){
            if(!used[v]) dfs(v);
        }
        memset(used, 0, sizeof(used));
        int k = 0;
        reverse(vs.begin(), vs.end());
        for(int v : vs){
            if(!used[v]) rdfs(v, k++);
        }
        return k;
    }

    ll get(int v) {
        if(dp[v] != -1) return dp[v];
        dp[v] = sum[v];
        ll mx = 0;
        for(auto e : cG[v]) {
            mx = max(mx, get(e.to) + e.cost);
        }
        return dp[v] += mx;
    }

    ll compute(int st) {
        sc = scc();
        for(int i = 0; i < n; i++) {
            for(auto e : G[i]) {
                if(cmp[i] == cmp[e.to]) sum[cmp[i]] += get_sum(e.cost);
                else cG[cmp[i]].push_back({cmp[e.to], e.cost});
            }
        }
        memset(dp, -1, sizeof(dp));
        return get(cmp[st]);
    }
} scc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 1; i < N; i++) {
        psum[i] = psum[i - 1] + 1LL * i * (i + 1) / 2;
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
        scc.add_edge(u, v, w);
    }
    int st;
    cin >> st; st--;
    cout << scc.compute(st) << endl;

}