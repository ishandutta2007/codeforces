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

    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;

    t -= 1LL << (s.back() - 'a');
    s.pop_back();
    t += 1LL << (s.back() - 'a');
    s.pop_back();

    sort(s.rbegin(), s.rend());

    for(auto &&c : s) {
        ll x = 1LL << (c - 'a');
        if(t > 0)
            t -= x;
        else
            t += x;
    }

    cout << (t == 0 ? "Yes\n" : "No\n");

    return 0;
}