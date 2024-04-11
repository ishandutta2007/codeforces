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
        cnt[--a[i]]++;
    }
    if(*max_element(ALL(cnt)) > (n + 1) / 2) {
        cout << -1 << "\n";
        return;
    }
    vector<pair<int, int>> ps;
    fill(ALL(cnt), 0);
    int l = a[0];
    rep(i, n - 1) if(a[i] == a[i + 1]) {
        ps.emplace_back(l, a[i]);
        cnt[l]++;
        cnt[a[i]]++;
        l = a[i];
    }
    ps.emplace_back(l, a.back());
    cnt[l]++;
    cnt[a.back()]++;
    int ans = ps.size() - 1U;
    int cost = *max_element(ALL(cnt)) - 1 - (int)ps.size();
    if(cost > 0) ans += cost;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}