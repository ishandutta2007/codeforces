#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const int LOGN = 20;

int n, m;
vector<int> adj[N];
pair<int, int> e[N];
bool b[N];
int up[LOGN][N];
int p[N], d[N];

struct DSU{
    int sz[N], p[N];
    DSU(){
        for(int i = 0; i < N; ++i)
            sz[i] = 1, p[i] = i;
    }

    int get_p(int x){
        if(x == p[x]) return x;
        return p[x] = get_p(p[x]);
    }
    bool unite(int u, int v){
        u = get_p(u);
        v = get_p(v);
        if(u == v)
            return false;

        if(sz[u] < sz[v])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;

        return true;
    }
} dsu;

void dfs(int u, int par){
    up[0][u] = par;
    for(int i = 1; i < LOGN; ++i)
        up[i][u] = up[i - 1][up[i - 1][u]];

    for(int to: adj[u]){
        if(to != par){
            d[to] = d[u] + 1;
            dfs(to, u);
        }
    }
}

void dfs_p(int u, int par){
    for(int to: adj[u]){
        if(to != par){
            p[to] += p[u];
            dfs_p(to, u);
        }
    }
}

int raise(int u, int t){
    for(int i = LOGN - 1; i >= 0; --i)
        if(t & (1 << i))
            u = up[i][u];
    return u;
}

int lca(int u, int v){
    if(d[u] > d[v])
        swap(u, v);

    if(d[u] != d[v]){
        int diff = d[v] - d[u];
        v = raise(v, diff);
    }

    if(u == v)
        return u;

    for(int i = LOGN - 1; i >= 0; --i)
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }

    return up[0][u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> e[i].first >> e[i].second;

    for(int i = 0; i < m; ++i){
        if(dsu.unite(e[i].first, e[i].second)){
            adj[e[i].first].push_back(e[i].second);
            adj[e[i].second].push_back(e[i].first);
            b[i] = true;
        }
    }

    dfs(1, 1);

    int target = m - (n - 1);
    for(int i = 0; i < m; ++i){
        if(b[i]) continue;

        int u = e[i].first, v = e[i].second;
        int c = lca(u, v);
        if(v == c) swap(u, v);

        if(u == c){
            p[1] += 1;
            int t = raise(v, d[v] - d[u] - 1);
            p[t] -= 1;
            p[v] += 1;
        }
        else{
            p[u] += 1;
            p[v] += 1;
        }
    }

    dfs_p(1, 1);

    for(int i = 1; i <= n; ++i)
        cout << (p[i] == target);
    cout << "\n";
}