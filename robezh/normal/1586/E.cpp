#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, q, m;
vi G[N];
vi to[N];
int par[N], dep[N];
bool vis[N];
int in[N];
vector<vi> res;

void dfs(int v, int d) {
    vis[v] = true;
    dep[v] = d;
    for (int nxt : G[v]) {
        if(!vis[nxt]) {
            to[v].push_back(nxt);
            par[nxt] = v;
            dfs(nxt, d + 1);
        }
    }
}

vi getpath(int a, int b) {
    vi pa, pb;
    bool sw = dep[a] > dep[b];
    if(sw) swap(a, b);
//    if(dep[a] > dep[b]) swap(a, b);
    while(dep[b] > dep[a]) {
        pb.push_back(b);
        b = par[b];
    }
    while(a != b) {
        pb.push_back(b);
        pa.push_back(a);
        a = par[a];
        b = par[b];
    }
    pa.push_back(a);
    reverse(all(pb));
    for (int x : pb) pa.push_back(x);
    if(sw) reverse(all(pa));
    return pa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0,  m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);

    cin >> q;
    while(q--) {
        int a, b; cin >> a >> b; a--, b--;
        in[a] ^= 1;
        in[b] ^= 1;
        res.push_back(getpath(a, b));
    }
    int cnt = 0;
    rep(i, 0, n) cnt += in[i];
    if(cnt == 0) {
        cout << "YES\n";
//        cout << sz(res) << '\n';
        for (auto &vs : res) {
            cout << sz(vs) << '\n';
            for (int x : vs) cout << x + 1 << " ";
            cout << '\n';
        }
    } else {
        cout << "NO\n";
        cout << cnt / 2 << '\n';
    }


}