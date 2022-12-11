#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    int side = (n - 1 + k - 1) / k;
    int ans = side * 2;
    if ((n + k - 2) % k == 0) ans--;
    cout << ans << "\n";
    for (int i = 1; i < n; i++) {
        cout << i + 1 << " " << max(i - k, 0) + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}