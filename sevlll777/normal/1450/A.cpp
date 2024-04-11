#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cb = 0;
        for (auto c : s) cb += (c == 'b');
        while (cb--) cout << 'b';
        for (auto c : s) {
            if (c != 'b') cout << c;
        }
        cout << '\n';
    }
}