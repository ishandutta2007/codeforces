#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INT_MAX;
    for(int ms = 0; ms < 27; ms++) {
        int x = ms, da = x % 3 - 1;
        x /= 3;
        int db = x % 3 - 1;
        x /= 3;
        int dc = x % 3 - 1;
        int na = a + da, nb = b + db, nc = c + dc;
        ans = min(ans, abs(na - nb) + abs(nb - nc) + abs(nc - na));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}