#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, m;
vector<int> G[N], rG[N], vs;
bool used[N];
int cmp[N];

struct edge {
    int to, cost;
};

vector<edge> sG[N];

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int nxt : G[v]){
        if(!used[nxt]) dfs(nxt);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int nxt : rG[v]){
        if(!used[nxt]) rdfs(nxt, k);
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

bool vis[N];
ll dep[N];
ll g[N];


void dfs(int v, ll d, int c) {
    dep[v] = d;
    vis[v] = true;
    for(auto &e : sG[v]) {
        if(cmp[e.to] != c) continue;
        if(!vis[e.to]) dfs(e.to, d + e.cost, c);
        else {
            g[c] = __gcd(g[c], abs(e.cost + dep[v] - dep[e.to]));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        add_edge(a, b);
        sG[a].push_back({b, c});
    }
    scc();
    memset(vis, 0, sizeof(vis));
    rep(i, 0, n) {
        if(!vis[i]) {
            dfs(i, 0, cmp[i]);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int v, s, t;
        cin >> v >> s >> t; v--;
        s = (t - s) % t;
        ll st = __gcd((ll)t, g[cmp[v]]);
        cout << (s % st == 0 ? "YES" : "NO") << '\n';
    }





}