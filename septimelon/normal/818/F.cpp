#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = max(((ll)sqrt(1 + 8 * n) - 1) / 2 - 100, 1LL); i <= n; ++i) {
        if (i * (i - 1) / 2 < n - i) {
            ans = max(ans, n - i + i * (i - 1) / 2);
        } else {
            ans = max(ans, (n - i) * 2);
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}