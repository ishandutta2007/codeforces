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
    vector<ll> a, b;
    rep(i, 2 * n) {
        int x, y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if(x == 0)
            a.push_back(y);
        else
            b.push_back(x);
    }

    sort(ALL(a));
    sort(ALL(b));

    double ans = 1e18;

    double sum = 0;
    rep(i, n) sum += sqrt(a[i] * a[i] + b[i] * b[i]);
    chmin(ans, sum);

    sum = 0;
    rep(i, n) sum += sqrt(a[i] * a[i] + b[n - 1 - i] * b[n - 1 - i]);
    chmin(ans, sum);

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(10);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}