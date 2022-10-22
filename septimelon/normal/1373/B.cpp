#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int c[2] = {0, 0};
    for (int i = 0; i < s.size(); ++i) {
        ++c[s[i] - '0'];
    }
    if (min(c[0], c[1]) % 2 == 1) {
        cout << "DA\n";
    } else {
        cout << "NET\n";
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