#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline void solve() {
    ll n, k;
    cin >> n >> k;
    ll a, b;
    cin >> a >> b;
    ll mn = 1e11;
    ll mx = -1e11;
    for (ll i = 1; i <= n; ++i) {
        ll l = i * k - a - b;
        mn = min(mn, n * k / gcd(n * k, l));
        mx = max(mx, n * k / gcd(n * k, l));
    }
    for (ll i = 1; i <= n; ++i) {
        ll l = i * k - a + b;
        mn = min(mn, n * k / gcd(n * k, l));
        mx = max(mx, n * k / gcd(n * k, l));
    }
    for (ll i = 0; i <= n; ++i) {
        ll l = i * k + a + b;
        mn = min(mn, n * k / gcd(n * k, l));
        mx = max(mx, n * k / gcd(n * k, l));
    }
    cout << mn << " " << mx << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}