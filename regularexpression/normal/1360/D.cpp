#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= k) ans = min(ans, n / i);
            if (n / i <= k) ans = min(ans, i);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}