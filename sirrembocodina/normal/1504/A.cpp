#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s = "a" + s;
        string t = s;
        reverse(t.begin(), t.end());
        if (s != t) {
            cout << "YES" << endl;
            cout << s << endl;
            continue;
        }
        s = s.substr(1) + "a";
        t = s;
        reverse(t.begin(), t.end());
        if (s != t) {
            cout << "YES" << endl;
            cout << s << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}