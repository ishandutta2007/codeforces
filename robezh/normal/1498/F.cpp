#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb subnb
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, k;
vi G[N];
int a[N];

struct Node {
    vi vs;
    Node() {
        vs = vi(2 * k, 0);
    }
};

Node operator+(Node a, Node b) {
    rep(i, 0, 2 * k) a.vs[i] ^= b.vs[i];
    return a;
}

Node append(int x, Node a) {
    int bk = x ^ a.vs.back();
    a.vs.pop_back();
    a.vs.insert(a.vs.begin(), bk);
    return a;
}

Node dp[N];
int res[N];

void solve(int v, int p) {
    dp[v] = Node();
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        solve(nxt, v);
        dp[v] = dp[v] + dp[nxt];
    }
    dp[v] = append(a[v], dp[v]);
}

void reroot(int v, int p, Node updp) {
    Node sdp = dp[v] + append(0, updp);
    int sum = 0;
    for (int i = k; i < 2 * k; i++) sum ^= sdp.vs[i];
    res[v] = (sum != 0);
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        reroot(nxt, v, sdp + append(0, dp[nxt]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n) cin >> a[i];
    solve(0, -1);
    reroot(0, -1, Node());
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}