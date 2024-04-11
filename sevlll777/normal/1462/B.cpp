#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

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
        string ans = "NO\n";
        for (int i = 0; i <= 4; i++) {
            string t = "";
            for (int h = 0; h < i; h++) t += s[h];
            for (int hh = n-(4-i); hh <= n-1; hh++) t += s[hh];
            if (t == "2020") ans = "YES\n";
        }
        cout << ans;
    }
}