#include <bits/stdc++.h>
using namespace std;

int cnt1[26], cnt2[26];

int main() {
    string s, t;
    cin >> s >> t;
    for(auto c : s)
        cnt1[c - 'a']++;
    for(auto c : t)
        cnt2[c - 'a']++;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt2[i] && !cnt1[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans += min(cnt1[i], cnt2[i]);
    }
    cout << ans << endl;
}