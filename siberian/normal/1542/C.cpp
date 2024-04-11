#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int MOD = 1e9 + 7;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    ll n;
    cin >> n;
    int ans = 0;
    int now = 1;
    for (int x = 2; now <= n; ++x) {
        // if (!isPrime(x)) continue;
        // cerr << "now = " << now << " x = " << x << endl;
        int cnt = n / now - n / lcm(now, x);
        // cerr << "cnt = " << cnt << endl;
        ans = ans + cnt * x;
        ans %= MOD;
        now = lcm(now, x);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}