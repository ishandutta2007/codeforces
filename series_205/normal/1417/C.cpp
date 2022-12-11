// #include <atcoder/all>
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>{-1});
    rep(i, n) {
        int x;
        cin >> x;
        x--;
        a[x].push_back(i);
    }
    rep(i, n) a[i].push_back(n);
    vector<int> ans(n, -1);

    rep(i, n) {
        int mx = 0;
        rep(j, (int)a[i].size() - 1) chmax(mx, a[i][j + 1] - a[i][j]);
        if(ans[mx - 1] == -1) ans[mx - 1] = i + 1;
    }

    rep(i, n) {
        cout << ans[i] << " \n"[i + 1 == n];
        if(i + 1 < n && ans[i] != -1) {
            if(ans[i + 1] == -1 || ans[i + 1] > ans[i]) ans[i + 1] = ans[i];
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}