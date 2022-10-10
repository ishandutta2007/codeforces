#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = x + 1;
    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if(y < x)
            ans = min(ans, (x - 1)/y + 1);
        if(y == x)
            ans = 1;
        if(y > x)
            ans = min(ans, 2);
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