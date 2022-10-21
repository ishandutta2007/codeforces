#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, k;
int a[N], dp[N], vis[N];
vi G[N];

int getval(int comp, int im0) {
    if(im0 != -1) return 1 + comp + im0;
    else return -(1 + comp);
}

void dfs(int v, int mn) {

    int comp = 0, imcomp = -1;
    vis[v] = 1;
    for(int nxt : G[v]) {
        if(vis[nxt]) continue;
        if(a[nxt] >= mn) dfs(nxt, mn);
        if(dp[nxt] < 0) comp += -dp[nxt];
        else imcomp = max(imcomp, dp[nxt]);
    }
    dp[v] = getval(comp, imcomp);
//    cout << v << ": " << dp[v] << endl;
}


void reroot(int v, int p, int mn, int up_val, int &res) {
    int comp = 0, im[2] = {-1, -1};
    vector<int> vs;
    if(p != -1) vs.push_back(up_val);
    for(int nxt : G[v]) if(nxt != p) vs.push_back(dp[nxt]);
    for(int val : vs) {
        if(val < 0) comp += -val;
        else rep(j, 0, 2) if(val > im[j]) swap(val, im[j]);
    }
    res = max(res, 1 + comp + max(0, im[0]));
    for(int nxt : G[v]) {
        if(nxt == p || a[nxt] < mn) continue;
        if(dp[nxt] < 0) reroot(nxt, v, mn, getval(comp + dp[nxt], im[0]), res);
        else {
            reroot(nxt, v, mn,
                   getval(comp, (dp[nxt] == im[0] ? im[1] : im[0])),
                   res);
        }
    }
}

int solve(int mn) {
    fill(vis, vis + n, 0);
    fill(dp, dp + n, 0);
    int res = 0;
    rep(i, 0, n) {
        if(vis[i] || a[i] < mn) continue;
        dfs(i, mn);
        reroot(i, -1, mn, -1, res);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

//    cout << solve(4) << endl;
//    rep(i, 0, 10) cout << solve(i) << " ";
//    cout << endl;


    int l = 0, r = (int)1e6 + 1, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(solve(mid) >= k) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}