#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
const int N = 2e5 + 3;
const int LOGN = 18;

array<int, 3> e[N];
vector<pair<int, int>> adj[N], adj2[N];
int n, m;
set<int> not_vis;
int dist[N], par[N], up[LOGN][N], d[N], cnt[N];
ll cnt0, ans_mst, ans;

void d_dfs(int u, int p = -1){
    for(auto [to, len]: adj2[u])
        if(to != p){
            d[to] = d[u] + 1;
            d_dfs(to, u);
        }
}

void init_lca(){
    par[1] = 1;
    for(int i = 1; i <= n; ++i)
        up[0][i] = par[i];
    for(int j = 1; j < LOGN; ++j)
        for(int i = 1; i <= n; ++i)
            up[j][i] = up[j - 1][up[j - 1][i]];
    d[1] = 0;
    d_dfs(1);
}

int get_lca(int x, int y){
    if(d[x] != d[y]){
        if(d[x] < d[y]) swap(x, y);
        int diff = d[x] - d[y];
        for(int i = LOGN - 1; i >= 0; --i)
            if((diff >> i) & 1)
                x = up[i][x];
    }
    if(x == y) return x;
    for(int i = LOGN - 1; i >= 0; --i)
        if(up[i][x] != up[i][y]){
            x = up[i][x];
            y = up[i][y];
        }
    return up[0][x];
}

void init_cnt(int u, int p = -1){
    for(auto [to, len]: adj2[u])
        if(to != p){
            cnt[to] = cnt[u];
            if(!len) ++ cnt[to];
            init_cnt(to, u);
        }
}

void do_checks(){
    init_cnt(1);
    for(int i = 0; i < m; ++i){
        int lca = get_lca(e[i][0], e[i][1]);
        int em_cnt = cnt[e[i][0]] + cnt[e[i][1]] - 2 * cnt[lca];
        if(em_cnt) check_min(ans, ans_mst + e[i][2]);
    }
}

void build_mst(){
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 1});
    for(int i = 1; i <= n; ++i){
        not_vis.insert(i);
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();

        if(dist[u] != du) continue;
        not_vis.erase(u);

        vector<int> add;
        for(auto [to, len]: adj[u]){
            if(len < dist[to] && not_vis.count(to)){
                dist[to] = len;
                par[to] = u;
                pq.push({dist[to], to});
            }
            if(not_vis.count(to)){
                not_vis.erase(to);
                add.push_back(to);
            }
        }

        for(int x: not_vis){
            par[x] = u;
            dist[x] = 0;
            pq.push({dist[x], x});
        }

        not_vis.clear();

        for(int x: add)
            not_vis.insert(x);
    }

    for(int i = 2; i <= n; ++i){
        if(!dist[i]) ++cnt0;
        adj2[i].push_back({par[i], dist[i]});
        adj2[par[i]].push_back({i, dist[i]});
        ans_mst += dist[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        adj[e[i][0]].push_back({e[i][1], e[i][2]});
        adj[e[i][1]].push_back({e[i][0], e[i][2]});
    }

    build_mst();
    if(cnt0 + m != (ll)n * (n - 1) / 2){
        cout << ans_mst << "\n";
        return 0;
    }

    ans = ans_mst;
    ll xor_e = 0;
    for(int i = 0; i < m; ++i)
        xor_e ^= e[i][2];
    ans += xor_e;

    init_lca();
    do_checks();

    cout << ans << "\n";
}