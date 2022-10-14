#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp0(n+1, 0), dp1(n+1,0);
    for (int i = 0; i < n; i++) {
        dp0[i+1]=dp0[i];
        dp1[i+1]=dp1[i];
        if (s[i] == '0') {
            dp0[i+1] = max(dp0[i+1], 1 + dp1[i]);
        } else {
            dp1[i+1] = max(dp1[i+1], 1+dp0[i]);
        }
    }
    cout << min(n, 2+max(dp0[n], dp1[n]));
}