#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    if (a < b) {
        swap(a, b);
    }
    int ans = 0;
    while (a <= n) {
        ++ans;
        b += a;
        swap(a, b);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}