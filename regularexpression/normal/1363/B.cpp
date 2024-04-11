#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> pref(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++) pref[i + 1] = pref[i] + (s[i] == '0');
        int ans = 1e9 + 7;
        for (int i = 0; i <= s.size(); i++) {
            int pref0 = pref[i], pref1 = i - pref[i];
            int suf0 = pref[s.size()] - pref0, suf1 = (int)s.size() - i - suf0;
            ans = min(ans, pref0 + suf1);
            ans = min(ans, pref1 + suf0);
        }
        cout << ans << '\n';
    }
    return 0;
}