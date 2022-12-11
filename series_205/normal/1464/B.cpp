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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    if(x > y) {
        swap(x, y);
        for(auto &&c : s)
            if(c != '?') c = '0' + '1' - c;
    }

    ll ans = inf;

    ll sx = 0, sy = 0, c0 = 0, c1 = 0, cc = 0;

    for(auto &&c : s) {
        if(c == '0') {
            sy += c1;
            c0++;
        } else {
            sx += c0;
            c1++;
            if(c == '?') cc++;
        }
    }

    c1 -= cc;

    chmin(ans, sx * x + sy * y);

    int cnt[3]{};
    for(auto &&c : s) {
        if(c == '0')
            cnt[0]++;
        else if(c == '1')
            cnt[1]++;
        else {
            sx -= cnt[0] + cnt[2];
            sy += cnt[1];
            cnt[2]++;
            sy -= c0 - cnt[0];
            sx += c1 - cnt[1] + cc - cnt[2];
            chmin(ans, sx * x + sy * y);
        }
    }

    cout << ans << endl;

    return 0;
}