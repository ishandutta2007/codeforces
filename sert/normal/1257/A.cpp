#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int dist = max(a, b) - min(a, b);
    cout << min(n - 1, dist + x) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) solve();
}