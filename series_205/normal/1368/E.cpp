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
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }

    vector<int> a(n), ans;

    rep(i, n) {
        if(a[i] >= 2) {
            ans.push_back(i);
            a[i] = -1;
        }
        for(int e : G[i])
            chmax(a[e], a[i] + 1);
    }
    cout << ans.size() << "\n";

    assert(ans.size() <= n * 4 / 7);

    rep(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}