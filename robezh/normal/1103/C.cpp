#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)3e5;

int n, m, k;
vi G[N];
int dep[N];
int vis[N], par[N];
int S[N], sz;
vector<vi> cycs;


void dfs(int v, int p, int d) {
    dep[v] = d;
    S[sz++] = v;
    par[v] = p;
    vis[v] = true;
    if(sz >= (n + k - 1) / k) {
        cout << "PATH\n";
        cout << sz << "\n";
        for(int i = 0; i < sz; i++) cout << S[i] + 1 << " ";
        cout << '\n';
        exit(0);
    }
    for (int nxt : G[v]) {
        if(!vis[nxt]) dfs(nxt, v, d + 1);
    }
    sz--;
}


void search(int v) {
    vis[v] = true;

    bool is_leaf = true;
    vi bs;
    for (int nxt : G[v]) {
        if(!vis[nxt]) {
            is_leaf = false;
            search(nxt);
        } else {
            if(nxt != par[v]) bs.push_back(nxt);
        }
    }
    if(is_leaf && sz(cycs) < k) {
        int a = bs[0], b = bs[1];
        if(dep[a] < dep[b]) swap(a, b);
        int s, t;
        if((dep[v] - dep[a] + 1) % 3 != 0) {
            s = par[v], t = par[a];
        } else if((dep[v] - dep[b] + 1) % 3 != 0) {
            s = par[v], t = par[b];
        } else {
            s = a, t = par[b];
        }
        vi new_cyc = {v};
        while(s != t) {
            new_cyc.push_back(s);
            s = par[s];
        }
        cycs.push_back(new_cyc);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    dfs(0, -1, 0);
    memset(vis, 0, sizeof(vis));
    search(0);
    cout << "CYCLES\n";
    rep(i, 0, k) {
        cout << cycs[i].size() << "\n";
        for(int x : cycs[i]) cout << x + 1 << " ";
        cout << "\n";
    }

}