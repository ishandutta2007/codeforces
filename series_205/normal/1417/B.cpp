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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int x = 0;
    if(t % 2 == 0) x = count(ALL(a), t / 2);
    int j = 0;
    rep(i, n) {
        if(i) cout << " ";
        if(a[i] * 2 < t)
            cout << 0;
        else if(a[i] * 2 > t)
            cout << 1;
        else {
            cout << ((j++) * 2 < x);
        }
    }
    cout << "\n";
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