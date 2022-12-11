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

int dmin(ll x) {
    int res = 100;
    while(x) {
        chmin<int>(res, x % 10);
        x /= 10;
    }
    return res;
}
int dmax(ll x) {
    int res = -100;
    while(x) {
        chmax<int>(res, x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        ll a, k;
        cin >> a >> k;
        rep(i, k - 1) {
            int x = dmin(a);
            int y = dmax(a);
            if(!x) break;
            a += x * y;
        }
        cout << a << "\n";
    }

    return 0;
}