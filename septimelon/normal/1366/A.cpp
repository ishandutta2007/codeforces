#include <iostream>

using namespace std;

void solve() {
    int a, b, delta, mi;
    cin >> a >> b;
    delta = max(b - a, a - b);
    mi = min(a, b);
    int ans = 0;
    if (delta >= mi) {
        ans = mi;
    } else {
        ans = delta;
        mi -= delta;
        ans += (mi / 3) * 2;
        mi %= 3;
        if (mi > 1) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main()
{
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