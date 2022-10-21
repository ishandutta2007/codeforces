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

int n;
int dp[N], vis[N], f[N], res[N];
vi G[N];

void dfs(int v, int p) {
    f[v] = p;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        dp[v] ^= 1 + dp[nxt];
    }
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
    dfs(0, -1);
    int v = dp[0];
    vis[0] = 1;
    res[0] = dp[0];
    int cnt = 0;
    rep(i, 1, n) {
        for (int j = i; !vis[j]; j = f[j]) {
            cnt++;
            v ^= dp[j] ^ (dp[j] + 1);
            vis[j] = 1;
        }
        res[i] = v ^ (cnt & 1);
    }
    rep(i, 0, n) cout << (res[i] == 0 ? '2' : '1');
    cout << '\n';




}