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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        rep(i, n) {
            cin >> v[i];
            v[i] = (v[i] % n + n) % n;
        }
        vector<bool> used(n);
        rep(i, n) used[(i + v[i]) % n] = 1;
        cout << (count(ALL(used), true) == n ? "YES" : "NO") << "\n";
    }
    cout << flush;

    return 0;
}