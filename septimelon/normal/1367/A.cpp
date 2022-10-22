#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string a;
    cin >> a;
    string b = "";
    b += a[0];
    for (int i = 1; i < a.size(); i += 2) {
        b += a[i];
    }
    cout << b << "\n";
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