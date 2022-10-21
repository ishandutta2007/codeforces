#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = (int)1e9;

const int N = 205;
int n, m;
int val[N];
int col[N];
vi G[N];
int dis[N][N];

struct edge {
    int u, v, b;
};

vector<edge> es;

void dfs(int v, int c) {
    col[v] = c;
    for(int nxt : G[v]) {
        if(col[nxt] == -1) {
            dfs(nxt, !c);
        } else if(col[nxt] != !c) {
            cout << "NO" << '\n';
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, b; cin >> u >> v >> b;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        es.push_back({u, v, b});
    }
    fill(col, col + n, -1);
    dfs(0, 0);
    rep(i, 0, n) {
        fill(dis[i], dis[i] + n, INF);
        dis[i][i] = 0;
    }
    for(auto &e : es) {
        int d0, d1;
        if(e.b) d0 = 1, d1 = -1;
        else d0 = 1, d1 = 1;
        dis[e.u][e.v] = d0;
        dis[e.v][e.u] = d1;
    }
    rep(k, 0, n)
        rep(i, 0, n)
            rep(j, 0, n) dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                if(dis[i][k] + dis[k][j] < dis[i][j]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    int mxi = -1, mxres = -1;
    rep(i, 0, n) {
        int cres = 0;
        rep(j, 0, n) cres = max(cres, dis[i][j]);
        if(cres > mxres) mxres = cres, mxi = i;
    }
    cout << "YES\n";
    cout << mxres << '\n';
    rep(i, 0, n) cout << dis[mxi][i] << " ";
    cout << "\n";


}