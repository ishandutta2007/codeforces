#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll x = (a + c - 1) / c;
    ll y = (b + d - 1) / d;
    if (x + y > k) cout << "-1\n";
    else cout << x << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) solve();
}