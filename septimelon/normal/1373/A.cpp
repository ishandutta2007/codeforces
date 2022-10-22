#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < c) {
        cout << "1 ";
    } else {
        cout << "-1 ";
    }
    if (a * b > c) {
        cout << b << "\n";
    } else {
        cout << "-1\n";
    }
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