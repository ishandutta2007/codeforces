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

const int N = (int)2e5 + 50;

int n;
vi G[N];
int res[N];

void dfs(int v, int p, int d) {
    res[v] = d * sz(G[v]);
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v, -d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, n - 1) {
            int u, v; cin >> u >> v; u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0, -1, 1);
        rep(i, 0, n) cout << res[i] << " ";
        cout << '\n';
    }

}