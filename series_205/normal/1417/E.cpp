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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    int x = 0;
    ll ans = 0;
    for(int i = 29; i >= 0; i--) {
        ll a0 = 0, a1 = 0;
        int t = (INT_MAX ^ ((1 << i + 1) - 1));
        sort(ALL(a), [&](auto x, auto y) {
            return make_pair((x.first & t), x.second) <
                   make_pair((y.first & t), y.second);
        });
        for(int j = 0, k = 0; j < n; j = k) {
            ll c0 = 0, c1 = 0;
            while(k < n && (t & a[j].first) == (t & a[k].first)) {
                if(a[k].first >> i & 1) {
                    c1++;
                    a0 += c0;
                } else {
                    c0++;
                    a1 += c1;
                }
                k++;
            }
        }
        if(a1 > a0) x += 1 << i;
        ans += min(a1, a0);
    }
    cout << ans << " " << x << endl;

    return 0;
}