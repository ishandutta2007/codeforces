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
const int N = (int)1e6 + 50;

int n, m;
int in[N], out[N];
int val[N], vis[N];
vi G[N];

void dfs(int v) {
    vis[v] = 1;
    for (int nxt : G[v]) {
        if(!vis[nxt]) dfs(nxt);
        val[v] |= val[nxt];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    int tcnt = 0;
    rep(i, 0, n) {
        if(out[i] == 0) {
            val[i] = (1 << (tcnt++));
        }
    }
    vi vs;
    rep(i, 0, n) {
        if(!vis[i]) dfs(i);
        if(in[i] == 0) {
            vs.push_back(val[i]);
//            cout << val[i] << endl;
        }
    }
    rep(i, 1, (1 << sz(vs)) - 1) {
        int s = 0;
        rep(j, 0, sz(vs)) if(i >> j & 1) s |= vs[j];
        if(__builtin_popcount(s) <= __builtin_popcount(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";


}