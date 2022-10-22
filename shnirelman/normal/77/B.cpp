#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    b *= 4;

    long double ans = 0.5;

    if(b == 0) {
        cout << setprecision(20) << fixed << 1 << endl;
        return;
    } else if(a == 0) {
        cout << setprecision(20) << fixed << 0.5 << endl;
        return;
    }


    if(a > b) {
        long double p = (long double)(a - b) / a / 2;
        ans += p;
        ans += (1 - ans) / 2;
    } else {
        long double p = (long double)(b - a) / b / 2;
        ans += (1 - ans - p) / 2;
    }

    cout << setprecision(20) << fixed << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}