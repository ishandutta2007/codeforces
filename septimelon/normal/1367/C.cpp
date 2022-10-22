#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] == '0') {
        ++ans;
        s[0] = '1';
        for (int i = 1; i <= k; ++i) {
            if (s[i] == '1') {
                s[0] = '0';
                --ans;
            }
        }
    }
    if (s[n - 1] == '0') {
        ++ans;
        s[n - 1] = '1';
        for (int i = 1; i <= k; ++i) {
            if (s[n - 1 - i] == '1') {
                s[n - 1] = '0';
                --ans;
            }
        }
    }
    int cl = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1') {
            ans += (i - cl - 1 - k) / (k + 1);
            cl = i;
        }
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