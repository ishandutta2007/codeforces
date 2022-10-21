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

const int N = (int)3e5 + 50;

int n;
int c[N];
vi G[N];
int gd[N], dp[N];
int res[N];

void dfs(int v, int p) {
    dp[v] = c[v];
    gd[v] = 0;
    int s = 0, d = 0;
    for (int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v);
            s += c[nxt];
            d += dp[nxt] > 0;
            gd[v] |= gd[nxt];
            dp[v] = max(dp[v], dp[nxt] + c[v]);
        }
    }
    gd[v] |= s >= 1 && d >= 2;
    gd[v] |= dp[v] >= 2;
}

void reroot(int v, int p, int ugd, int udp) {
//    cout << v + 1 << " " << p + 1 << " " << ugd << " " << udp << endl;
    pii mx[2] = {{udp + c[v], p}, {c[v], -1}};
    int g = ugd;
    int s = (p == -1 ? 0 : c[p]), d = udp > 0;
    for (int nxt : G[v]) {
        if(nxt != p) {
            g += gd[nxt];
            s += c[nxt];
            d += dp[nxt] > 0;
            pii px = {dp[nxt] + c[v], nxt};
            rep(j, 0, 2) if(px > mx[j]) swap(px, mx[j]);
        }
    }
    res[v] |= c[v];
    res[v] |= s >= 1 && d >= 2;
    res[v] |= mx[0].first >= 2 || g > 0;
    for (int nxt : G[v]) {
        if(nxt != p) {
            int nxt_gd = g - gd[nxt] > 0 || (s - c[nxt] >= 1 && d - (dp[nxt] > 0) >= 2);
            int nxt_dp = (mx[0].second == nxt ? mx[1].first : mx[0].first);
            reroot(nxt, v, nxt_gd, nxt_dp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    reroot(0, -1, 0, 0);
    rep(i, 0, n) cout << res[i] << " ";
//    rep(i, 0, n) {
////        cout << "d " << i + 1 << endl;
//        dfs(i, -1);
//        cout << (gd[i] || c[i]) << " ";
//    }
    cout << endl;
}