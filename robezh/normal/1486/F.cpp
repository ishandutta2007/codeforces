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

const int N = (int)3e5 + 50, LOGN = 19;

int n;
vector<int> G[N];
int parent[LOGN][N];
int depth[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(){
    dfs(0, -1, 0);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
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

int jp(int v, int d) {
    for(int k = 0; k < LOGN; k++){
        if(d >> k & 1) v = parent[k][v];
    }
    return v;
}

int m;
vector<pii> es[N];
int sub[N];
ll res = 0;

void calc(int v, int p) {
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        calc(nxt, v);
        sub[v] += sub[nxt];
    }
//    cout << v << " " << sub[v] << endl;
    map<pii, int> mp;
    for (auto e : es[v]) {
        if(e.first != v) {
            sub[v]--;
            mp[e]++;
        }
    }
    for(auto e : es[v]) {
        if(e.first == v) {
            if(e.second == v) {
                res += sub[v] - 1;
            } else {
                res += sub[v] - sub[e.second];
            }
        } else {
            res += sub[v] - sub[e.second] - sub[e.first] + mp[e];
        }
    }
    sub[v] -= sz(es[v]);


    map<int, int> cnt;
    int tot = sz(es[v]);

    for (auto e : es[v]) {
        if(e.first != v) cnt[e.first]++;
        if(e.second != v) cnt[e.second]++;
    }
    ll pres = 0;
    for(auto e : es[v]) {
        if(e.first == v) {
            if(e.second == v) pres += tot - 1;
            else pres += tot - cnt[e.second];
        } else {
            pres += tot - cnt[e.second] - cnt[e.first] + mp[e];
        }
    }
    res -= pres / 2;

//    cout << v << " " << sub[v] << " " << res << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();
    cin >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        int ca = lca(a, b);
//        cout << a << " " << b << " " << ca << endl;
        if(a != ca) {
            sub[a]++;
            a = jp(a, depth[a] - depth[ca] - 1);
        }
        if(b != ca) {
            sub[b]++;
            b = jp(b, depth[b] - depth[ca] - 1);
        }
        if(a == ca && b == ca) sub[ca]++;
        if(depth[a] > depth[b] || (depth[a] == depth[b] && a > b)) swap(a, b);
//        cout << a << " " << b << " " << ca << endl;
        es[ca].push_back({a, b});
    }
    calc(0, -1);
    cout << res << endl;
//    cout << res / 2 << endl;

}