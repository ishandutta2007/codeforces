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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> l(n), r(n);
    rep(i, n - 1) if(a[i + 1] > a[i]) l[i + 1] = l[i] + 1;
    FORR(i, n - 1) if(a[i] > a[i + 1]) r[i] = r[i + 1] + 1;

    int mx = max(*max_element(ALL(l)), *max_element(ALL(r)));
    int cnt = 0;
    rep(i, n) if(l[i] == mx || r[i] == mx) cnt++;
    if(cnt > 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;

    rep(i, n) if(l[i] == mx && r[i] == mx && mx % 2 == 0) ans++;

    cout << ans << endl;

    return 0;
}