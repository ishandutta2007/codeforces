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

ll n;
ll a[200009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, n) cin >> a[i];

    if(n == 1) {
        cout << "1 1\n";
        cout << "0\n";
        cout << "1 1\n";
        cout << "0\n";
        cout << "1 1\n";
        cout << -a[0] << "\n";
        return 0;
    }

    cout << 1 << " " << n - 1 << endl;
    rep(i, n - 1) cout << (i ? " " : "") << (n - 1) * a[i];
    cout << endl;
    cout << 2 << " " << n << endl;
    rep(i, n - 2) cout << 0 << " ";
    cout << (n - 1) * a[n - 1] << endl;
    cout << 1 << " " << n << endl;
    rep(i, n) cout << -a[i] * n << " \n"[i + 1 == n];

    return 0;
}