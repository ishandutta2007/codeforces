#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        int n = s.size();
        string w(n, '1');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i - x >= 0) w[i - x] = '0';
                if (i + x < n) w[i + x] = '0';
            }
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                bool cur = 0;
                cur |= i - x >= 0 && w[i - x] == '1';
                cur |= i + x < n && w[i + x] == '1';
                ok &= cur;
            }
        }
        if (!ok) cout << -1; else cout << w;
        cout << '\n';
    }
    return 0;
}