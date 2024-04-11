#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50, LOGN = 18;

struct edge {
    int to, id;
};

int n, m, q;
vector<edge> G[N];
vi H[N];
int low[N], pre[N];
int ccnt = 0;
int vis[N];
int parent[LOGN][N], depth[N];
int color[2][LOGN][N];
int cp[N];
int cmp[N];
int cmpcnt;
stack<int> S;
int cnt = 0;

void tarjan(int v, int id) {
    pre[v] = low[v] = ++cnt;
    S.push(v);
    for(int j = 0; j < G[v].size(); j++) {
        edge e = G[v][j];
        if(e.id == id) continue;
        if(pre[e.to] == 0) {
            tarjan(e.to, e.id);
            low[v] = min(low[v], low[e.to]);
        }
        else low[v] = min(low[v], pre[e.to]);
    }

    if(pre[v] == low[v]) {
        int cur;
        do {
            cur = S.top(); S.pop();
            cmp[cur] = ccnt;
        } while(cur != v);
        ccnt++;
    }
}

void dfs(int v, int p, int d, int ccmp) {
    vis[v] = 1;
    parent[0][v] = p;
    depth[v] = d;
    cp[v] = ccmp;

    for (int nxt : H[v]) {
        if(!vis[nxt]) {
            dfs(nxt, v, d + 1, ccmp);
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

void color_path(int v, int ca, int c) {
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[ca]) >> k & 1){
            color[c][k][v] = 1;
            v = parent[k][v];
//            cout << v << endl;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    rep(i, 0, n) {
        if(!pre[i]) tarjan(i, -1);
    }
    rep(i, 0, n) {
        for (auto &e : G[i]) {
            if(cmp[i] != cmp[e.to]) {
//                cout << i << " " << cmp[i] << " to " << e.to << " "<< cmp[e.to] << endl;
                H[cmp[e.to]].push_back(cmp[i]);
                H[cmp[i]].push_back(cmp[e.to]);
            }
        }
    }
    rep(i, 0, ccnt) {
        if(!vis[i]) dfs(i, -1, 0, cmpcnt++);
    }

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < ccnt; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }

    rep(i, 0, q) {
        int s, t; cin >> s >> t; s--, t--;
        s = cmp[s], t = cmp[t];
        if(cp[s] != cp[t]) {
//            cout << "not in same cmp" << endl;
            cout << "No\n";
            return 0;
        }
        int ca = lca(s, t);
//        cout << s << " " << t << " " << ca << endl;
        color_path(s, ca, 0);
        color_path(t, ca, 1);
    }

    for(int k = LOGN - 1; k >= 1; k--){
        for(int v = 0; v < ccnt; v++){
            if(parent[k][v] >= 0) {
                rep(c, 0, 2) {
                    color[c][k - 1][v] |= color[c][k][v];
                    color[c][k - 1][parent[k - 1][v]] |= color[c][k][v];

                }
            }
        }
    }
    rep(i, 0, ccnt) {
        if(color[0][0][i] && color[1][0][i]) {
            return cout << "No\n", 0;
        }
    }
    cout << "Yes\n";

}