#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int ans = x * (n / x) + y;
    if(ans > n)
        ans -= x;
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