#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 19, M = (1 << 18) + 5, INF = (int)2e9;

int n, m;
int rc[N], w[N];
int dp[N][M], mk[N][M];
vector<int> G[N];
int res[N];
int in[N];
vi idx;

int dfs(int v) {
    if(rc[v] != -1) return rc[v];
    rc[v] = (1 << v);
    for(int nxt : G[v]) {
        rc[v] |= dfs(nxt);
    }
    return rc[v];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, x; cin >> u >> v >> x; u--, v--;
        w[u] += x;
        w[v] -= x;
        G[u].push_back(v);
        in[v]++;
    }
    memset(rc, -1, sizeof(rc));
    rep(i, 0, n) if(rc[i] == -1) dfs(i);
    rep(i, 0, n) rc[i] ^= (1 << i);

    queue<int> que;
    rep(i, 0, n) if(in[i] == 0) que.push(i), idx.push_back(i);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nxt : G[v]) {
            in[nxt]--;
            if(in[nxt] == 0) {
                que.push(nxt);
                idx.push_back(nxt);
            }
        }
    }
//    rep(i, 0, n) cout << idx[i] << " ";
//    cout << endl;
    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + M, INF);
    dp[0][0] = 0;
    rep(i, 0, n) {
        if(i > 0) rep(mask, 0, (1 << n)) dp[i][mask] = dp[i - 1][mask];
        for(int nxt : idx) {
            rep(mask, 0, (1 << n)) {
                if(dp[i][mask] != -INF && !(mask >> nxt & 1) && ((mask | rc[nxt]) == mask)) {
                    if(dp[i][mask] + w[nxt] * i < dp[i][mask | (1 << nxt)]) {
                        dp[i][mask | (1 << nxt)] = dp[i][mask] + w[nxt] * i;
                        mk[i][mask | (1 << nxt)] = mk[i][mask] | (1 << nxt);
                    }
                }
            }
        }
    }
    int cur = (1 << n) - 1;

    for(int i = n - 1; i >= 0; i--) {
//        cout << bitset<10>(cur) << endl;
        for(int j = 0; j < n; j++) {
            if(mk[i][cur] >> j & 1) res[j] = i;
        }
        cur ^= mk[i][cur];
    }
//    cout << cur << endl;
    rep(i, 0, n) cout << res[i] << " ";
    cout << "\n";


}