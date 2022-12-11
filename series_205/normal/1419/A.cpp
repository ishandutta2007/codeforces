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
    string s;
    cin >> n >> s;
    if(n & 1) {
        int ans = 2;
        for(int i = 0; i < n; i += 2)
            if(s[i] - '0' & 1) ans = 1;
        cout << ans << "\n";
    } else {
        int ans = 1;
        for(int i = 1; i < n; i += 2)
            if((s[i] - '0') % 2 == 0) ans = 2;
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}