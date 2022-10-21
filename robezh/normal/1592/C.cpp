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
const int N = (int)1e5 + 50;

int n, k, a[N];
vi G[N];
int sub[N], cnt[N];

void dfs(int v, int p) {
    sub[v] = a[v];
    for (int nxt : G[v]) {
        if(nxt == p) continue;;
        dfs(nxt, v);
        sub[v] ^= sub[nxt];
    }
}

bool solve(int v, int p, bool in) {
    int ct = 0;
    bool res = false;
    cnt[v] = (sub[v] == sub[0]);
    if(in && sub[v] == sub[0]) return true;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        res |= solve(nxt, v, in || (sub[v] == 0));
        ct += (cnt[nxt] > 0);
        cnt[v] += cnt[nxt];
    }
    if(ct >= 2) res = true;
    return res;
}

bool solve() {
    cin >> n >> k;
    rep(i, 0, n) G[i].clear();

    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    if(sub[0] == 0) {
        return true;
    }
    if(k >= 3 && solve(0, -1, false)) {
        return true;
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}