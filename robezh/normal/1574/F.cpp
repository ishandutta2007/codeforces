#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int N = (int)3e5 + 50, mod = 998244353;

int n, m, k;
set<int> G[N], in[N];
int vis[N];
int cnt[N];
ll dp[N];

int dfs(int v) {
    vis[v] = 1;

    if(sz(G[v]) > 1) return -1;
    if(sz(G[v]) == 0) return 1;
    int nxt = *G[v].begin();
    if(sz(in[nxt]) > 1) return -1;
    if(vis[nxt]) return -1;

    int val = dfs(nxt);
    if(val == -1) return -1;
    return val + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) {
        int c; cin >> c;
        int la = -1, x;
        while(c--) {
            cin >> x; x--;
            if(la != -1) G[la].insert(x), in[x].insert(la);
            la = x;
        }
    }
    rep(i, 0, k) {
        if(!vis[i] && in[i].empty()) {
            int v = dfs(i);
            if(v != -1) cnt[v]++;
        }
    }
    dp[0] = 1;
    vector<pii> st;
    rep(i, 1, k + 1) {

        if(cnt[i]) {
            st.push_back({i, cnt[i]});
//            cout << i << " " << cnt[i] << endl;

        }
    };
    rep(j, 1, m + 1) {
        for (auto &p : st) {
            if(j >= p.first) dp[j] = (dp[j] + dp[j - p.first] * p.second) % mod;
        }
    }
    cout << dp[m] << '\n';




}