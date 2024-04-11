#include <vector>
#include <iostream>
#include <string>
#include <cmath>

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
    int p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    if (w < s) {
        swap(s, w);
        swap(cs, cw);
    }

    int ans = 0;
    int tp = 0, tf = 0;
    while (tp + s <= p && cs > 0) {
        tp += s;
        --cs;
        ++ans;
    }
    while (tf + s <= f && cs > 0) {
        tf += s;
        --cs;
        ++ans;
    }
    cs = ans;

    while (tp >= 0 && tf <= f) {
        ans = max(ans, cs + min(cw, (p - tp) / w + (f - tf) / w));
        tp -= s;
        tf += s;
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