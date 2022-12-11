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

char c[11] = "codeforces";

ll ppow(ll x, ll k = 10) {
    ll ret = 1;
    while(k) {
        if(k & 1) ret *= x;
        x *= x;
        k >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    int i = 0;
    while(ppow(i) < k)
        i++;

    rep(j, 11) {
        if(ppow(i - 1, 10 - j) * ppow(i, j) >= k) {
            rep(x, 10) cout << string((x < j ? i : i - 1), c[x]);
            cout << endl;
            return 0;
        }
    }

    return 0;
}