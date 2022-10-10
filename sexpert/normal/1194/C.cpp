#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int ct[26];
    fill(ct, ct + 26, 0);
    string s, t, p;
    cin >> s >> t >> p;
    for(auto c : p)
        ct[c - 'a']++;
    int p1 = 0, p2 = 0;
    while(p1 < s.size() && p2 < t.size()) {
        if(s[p1] == t[p2])
            p1++;
        p2++;
    }
    if(p1 < s.size()) {
        cout << "NO\n";
        return;
    }
    for(auto c : t)
        ct[c - 'a']--;
    for(auto c : s)
        ct[c - 'a']++;
    for(int i = 0; i < 26; i++) {
        if(ct[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}