#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 34;

void solve() {
    int n;
    cin >> n;
    int ans = INF;
    for (int i = 1; i * i <= n * 2; i++) {
        ans = min(ans, i + (n + i - 1) / i - 2);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}