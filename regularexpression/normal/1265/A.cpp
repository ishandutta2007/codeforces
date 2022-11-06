#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()

#define int long long

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < sz(s) - 1; i++) {
        if (s[i] == s[i + 1] && s[i] != '?') {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?') {
            set<char> st;
            if (i != 0) st.insert(s[i - 1]);
            if (i != sz(s) - 1) st.insert(s[i + 1]);
            for (int c = 0; c < 3; c++) {
                if (st.find('a' + c) == st.end()) {
                    s[i] = 'a' + c;
                    break;
                }
            }
        }
    }
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}