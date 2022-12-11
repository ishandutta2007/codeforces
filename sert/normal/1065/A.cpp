#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c, s;
    cin >> s >> a >> b >> c;
    ll k = s / (a * c);
    cout << k * (a + b) + (s - k * c * a) / c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) solve();
}