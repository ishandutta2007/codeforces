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
        string s;
        cin >> s;
        int ans = (s[0] - '0') * 10;
        ans += s.size()*(s.size()+1)/2;
        cout << ans-10;
        cout << '\n';
    }
}