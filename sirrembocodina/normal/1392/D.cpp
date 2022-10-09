#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int solve(string& s) {
    vector<string> t = {"RL", "RRL", "RLL", "RRLL"};
    int n = s.size();
    vector<int> d(n + 1, n);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t.size(); j++) {
            if (i + t[j].size() > n) {
                continue;
            }
            int cur = 0;
            for (int k = 0; k < t[j].size(); k++) {
                cur += s[i + k] != t[j][k];
            }
            d[i + t[j].size()] = min(d[i + t[j].size()], d[i] + cur);
        }
    }
    return d[n];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < 4; i++) {
            ans = min(ans, solve(s));
            s = s.substr(1) + s[0];
        }
        cout << ans << endl;
    }
}