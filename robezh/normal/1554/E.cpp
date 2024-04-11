#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, mod = 998244353;

int n;
vi G[N];
vi dvs[N];
ll pw[N], res[N];

int dfs(int v, int p, int d) {
    int sum = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        int val = dfs(nxt, v, d);
        if(val == -1) return -1;
        sum += val;
    }
    if(sum % d == 0) return 1;
    else if((sum + 1) % d == 0) return 0;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) dvs[j].push_back(i);
    }
    pw[0] = 1;
    rep(i, 1, N) pw[i] = (pw[i - 1] * 2) % mod;

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
        fill(res, res + n + 1, 0);
        res[1] = pw[n - 1];
        for(int d : dvs[n - 1]) {
            res[d] = max(0, dfs(0, -1, d));
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 2 * i; j <= n; j += i) {
                res[i] = (res[i] - res[j] + mod) % mod;
            }
        }
        rep(i, 1, n + 1) cout << res[i] << " ";
        cout << '\n';
    }


}