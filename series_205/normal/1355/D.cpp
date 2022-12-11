#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, s;
    cin >> n >> s;

    if(n * 2 > s) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    rep(i, n - 1) {
        cout << 2 << " ";
        s -= 2;
    }
    cout << s << endl;

    cout << 1 << endl;

    return 0;
}