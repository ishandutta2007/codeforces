#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '1';
    }

    vector<ll> prefs(n * 13, 0LL);
    ++prefs[n * 2];
    int cps = 0;
    for (int i = 0; i < a.size(); ++i) {
        cps += a[i];
        ++prefs[cps + n * 2];
    }

    ll ans = 0LL;
    for (int i = 0; i < prefs.size(); ++i) {
        ans += prefs[i] * (prefs[i] - 1) / 2LL;
    }

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