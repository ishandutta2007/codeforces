#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int a = -1, b = 1000000010, c = -1;
    for(int d = 2; d * d <= n; d++) {
        if(n % d)
            continue;
        a = d;
        n /= d;
        break;
    }
    if(a == -1) {
        cout << "NO\n";
        return;
    }
    for(int d = 2; d * d <= n; d++) {
        if(n % d)
            continue;
        if(d > a)
            b = min(b, d);
        if(n / d > a)
            b = min(b, n / d);
    }
    if(b == 1000000010) {
        cout << "NO\n";
        return;
    }
    c = n / b;
    if(b >= c) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << a << " " << b << " " << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}