#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

void sl() {
    int k;
    cin >> k;
    string ans = "";
    for (int x = 61; x >= 0; x--) {
        while ((1LL << (x+2)) - 2 <= k) {
            k -= ((1LL << (x+2)) - 2);
            for (int _ = 0; _ < x; _++) ans += '0';
            ans += '1';
        }
    }
    if (k) {
        cout << "-1\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto c : ans) cout << c << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        sl();
    }
}