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
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;

int res[N];

struct Euler {
    struct edge {
        // c is orientation of the edge
        int to, id, c;
    };
    vector<vector<edge>> G;
    vi pt, evis, path;

    Euler(int n, int m): G(n), pt(n, 0), evis(m, 0){};

    void add_edge(int u, int v, int eid) {
        G[u].push_back({v, eid, 0});
        G[v].push_back({u, eid, 1});
    }

    void dfs(int v){
        int &i = pt[v];
        while(true){
            while(i < sz(G[v]) && evis[G[v][i].id]) i++;
            if(i == sz(G[v])) break;
            auto e = G[v][i++];
            evis[e.id] = 1;
            dfs(e.to);
            res[e.id] = e.c;
            path.push_back(v);
        }
    }

    void get_path() {
        rep(i, 0, sz(G)) {
            if(pt[i] < sz(G[i])) {
                dfs(i);
            }
        }
    }
};

int n, m;
int deg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int tm = m;
    Euler euler(N, N);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        if(w == 2) u += n, v += n;
        euler.add_edge(u, v, i);
    }
    int rs = 0;
    rep(i, 0, n) if(sz(euler.G[i]) % 2 == 1) rs++;
    rep(i, 0, n) {
        if(sz(euler.G[i]) % 2 == 1 && sz(euler.G[i + n]) % 2 == 1) {
            euler.add_edge(i, i + n, m++);
        }
    }
    rep(i, 0, 2 * n) {
        if(sz(euler.G[i]) % 2 == 1) euler.add_edge(i, 2 * n, m++);
    }

    euler.get_path();

    cout << rs << '\n';
    rep(i, 0, tm) cout << (res[i] ? "1" : "2");
    cout << '\n';

}