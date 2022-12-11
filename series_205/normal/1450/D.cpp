#include <bits/stdc++.h>
// #include <atcoder/all>
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
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    vector<int> ans(n, 1);
    int mn = 0;
    rep(i, n) if(cnt[i] == 0) chmax(mn, n - i);
    fill(ans.begin(), ans.begin() + mn, 0);
    int l = 0, r = n - 1;
    for(int i = 0; 1 < n - i - 1; i++) {
        if(cnt[i] > 1 || (cnt[i] && a[l] != i && a[r] != i)) {
            fill(ans.begin() + 1, ans.begin() + n - i - 1, 0);
            break;
        }
        if(a[l] == i) l++;
        if(a[r] == i) r--;
    }
    rep(i, n) cout << ans[i];
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}