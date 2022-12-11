#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n;
ll a[200009];
int b[200009];

vector<int> r, G[200009];

vector<int> ans;

bool used[200009];

void dfs2(int v) {
    used[v] = true;
    ans.push_back(v);
    for(auto &&u : G[v])
        if(!used[u]) dfs2(u);
}

void dfs(int v) {
    for(auto &&u : G[v]) {
        dfs(u);
        if(a[u] > 0) a[v] += a[u];
    }
    if(a[v] <= 0) dfs2(v);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> b[i];
        if(~b[i]) {
            b[i]--;
            G[b[i]].push_back(i);
        } else
            r.push_back(i);
    }

    for(auto &&x : r) {
        dfs(x);
        if(!used[x]) dfs2(x);
    }

    ll res = 0;
    rep(i, n) res += a[i];
    cout << res << endl;
    reverse(ALL(ans));
    rep(i, n) cout << ans[i] + 1 << " \n"[i == n - 1];

    return 0;
}