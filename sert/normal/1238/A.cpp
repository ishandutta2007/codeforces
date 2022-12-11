#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    ll x, y;
    cin >> x >> y;
    cout << (x - 1 == y ? "NO" : "YES") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) solve();
}