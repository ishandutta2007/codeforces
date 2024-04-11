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
#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

struct edge {
    int to, id;
};

int n, m;
vector<edge> G[N];

vector<int> T[N * 2];

struct BCC {
    int dfn[N * 2], low[N], dfc;
    int stk[N], tp, cnt;

    void tarjan(int u) {
        low[u] = dfn[u] = ++dfc;
        stk[++tp] = u;
        for (auto &e : G[u]) {
            int v = e.to;
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
                if (low[v] == dfn[u]) {
                    ++cnt;
                    for (int x = 0; x != v; --tp) {
                        x = stk[tp];
                        T[cnt].push_back(x);
                        T[x].push_back(cnt);
                    }
                    T[cnt].push_back(u);
                    T[u].push_back(cnt);
                }
            } else
                low[u] = std::min(low[u], dfn[v]);
        }
    }

    void compute(int n) {
        cnt = n;
        for(int i = 0; i < n; i++) {
            if(!dfn[i]) {
                tarjan(i);
            }
        }
    }
} bcc;


int chainNo, top[N * 2], dfn[N * 2], totsize, ord[N * 2], dep[N * 2];
int subsize[N * 2], par[N * 2];

struct HLD {
    int n;

    void dfs(int v, int p, int d){
        par[v] = p;
        subsize[v] = 1;
        dep[v] = d;
        for(int &nxt : T[v]){
            if(nxt == p) continue;
            dfs(nxt, v, d+1);
            subsize[v] += subsize[nxt];
            if(T[v][0] == p || subsize[nxt] > subsize[T[v][0]])
                swap(nxt, T[v][0]);
        }
    }

    void hld(int v, int p, int tp){

        top[v] = tp;
        dfn[v] = totsize;
        ord[totsize++] = v;

        for(auto nxt : T[v]){
            if(nxt == p) continue;
            if(nxt != T[v][0]) {
                chainNo ++;
                hld(nxt, v, nxt);
            } else {
                hld(nxt, v, tp);
            }
        }
    }


    void init_hld(int V){
        n = V;
        chainNo = totsize = 0;
        fill(dfn, dfn + n, -1);
        rep(i, 0, n) {
            if(dfn[i] == -1) {
                dfs(i, -1, 0);
                hld(i, -1, i);
            }
        }
    }

    int query(int a, int b) {
        int res = dep[a] + dep[b];
        while(top[a] != top[b]) {
//                cout << a << " " << b << endl;
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            a = par[top[a]];
        }
        if(dfn[a] > dfn[b]) swap(a, b);
        return res - 2 * dep[a];
    }
} hld;
int q;
int w[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
//    rep(i, 0, n) cin >> w[i];
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    bcc.compute(n);

    hld.init_hld(bcc.cnt);


    while(q--) {
        int a, b;
        cin >> a >> b; a--, b--;
        cout << hld.query(a, b) / 2 << '\n';

    }


}