#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int cnt[26];
string s, t, p;

bool solve() {
    cin >> s >> t >> p;
    for(char c : p) cnt[c - 'a']++;
    int cur = 0;
    for(char c : t) {
        if(cur < s.length() && c == s[cur]) cur++;
        else {
            if(cnt[c - 'a'] == 0) return false;
            cnt[c - 'a']--;
        }
    }
    return cur == s.length();
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        cout << (solve() ? "YES" : "NO") << endl;
    }
}