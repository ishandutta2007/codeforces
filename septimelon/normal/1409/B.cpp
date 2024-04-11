#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 1000000000000000000LL;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll att(ll a, ll x, ll b, ll y, ll n) {
    ll delta = min(n, a - x);
    a -= delta;
    n -= delta;
    delta = min(n, b - y);
    b -= delta;
    n -= delta;

    return a * b;
}

void solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll ans = INF;
    ans = att(a, x, b, y, n);
    ans = min(ans, att(b, y, a, x, n));

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}