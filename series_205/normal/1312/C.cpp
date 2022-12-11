#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> cnt(100);
        rep(i, n) {
            ll a;
            cin >> a;
            for(int i = 0; a; i++, a /= k)
                cnt[i] += a % k;
        }
        bool ok = true;
        rep(i, 100) {
            if(cnt[i] > 1) ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}