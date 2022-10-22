#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, m;
vector<int> G[N];
int res[N];

void dfs(int v) {
    res[v] = 1;
    vi unvis;
    for(int nxt : G[v]) if(res[nxt] == -1) {
        res[nxt] = 0;
        unvis.push_back(nxt);
    }
    for(int nxt : unvis) {
        for(int nxt2 : G[nxt]) {
            if(res[nxt2] == -1) {
                dfs(nxt2);
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    rep(i, 0, n) G[i].clear();
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(res, res + n, -1);
    dfs(0);
    vi vs;
    rep(i, 0, n) {
        if(res[i] == -1) {
            cout << "NO\n";
            return;
        } else if(res[i]) vs.push_back(i);
    }
    cout << "YES\n";
    cout << sz(vs) << '\n';
    for(int x : vs) cout << x + 1 << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }


}