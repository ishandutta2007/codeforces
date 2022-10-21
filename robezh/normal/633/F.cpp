#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, a[N];
vi G[N];
ll dp[N], ct[N];
ll res = 0;

void dfs(int v, int p) {
    ll mx[2] = {0, 0};
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        dp[v] = max(dp[v], dp[nxt]);
        ll cct = ct[nxt];
        for(int j = 0; j < 2; j++) if(cct > mx[j]) swap(cct, mx[j]);
    }
    dp[v] = max(dp[v], a[v] + mx[0] + mx[1]);
//    cout << v << " " << dp[v] << endl;
    ct[v] = mx[0] + a[v];
}

void reroot(int v, int p, ll up_dp, ll up_ct) {
    ll mx_dp[2] = {0, 0}, mx_ct[3] = {0, 0, 0};
    vector<pll> ps;
    if(p != -1) ps.push_back({up_dp, up_ct});
    for(int nxt : G[v]) if(nxt != p) ps.push_back({dp[nxt], ct[nxt]});
    for(pll &p : ps) {
        ll curdp = p.first, curct = p.second;
        rep(i, 0, 2) if(curdp > mx_dp[i]) swap(curdp, mx_dp[i]);
        rep(i, 0, 3) if(curct > mx_ct[i]) swap(curct, mx_ct[i]);
    }

    for(int nxt : G[v]) {
        if(nxt == p) continue;
        ll nxtdp = max((mx_dp[0] == dp[nxt] ? mx_dp[1] : mx_dp[0]),
                        (mx_ct[0] == ct[nxt] ? mx_ct[1] + mx_ct[2] :
                         (mx_ct[1] == ct[nxt] ? mx_ct[0] + mx_ct[2] : mx_ct[0] + mx_ct[1])) + a[v]);
        ll nxtct = (mx_ct[0] == ct[nxt] ? mx_ct[1] : mx_ct[0]) + a[v];
//        cout << "cut at " << nxt << " " << v << ": " << nxtdp << ", " << dp[nxt] << endl;
        res = max(res, nxtdp + dp[nxt]);
        reroot(nxt, v, nxtdp, nxtct);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    reroot(0, -1, -1, -1);
    cout << res << '\n';
}