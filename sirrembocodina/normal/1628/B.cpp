#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int mod = 998244353;

int32_t main() {
    __int128 t;
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        bool ok = false;
        vector<string> s(n);
        forn (i, n) {
            cin >> s[i];
        }
        set<string> ss;
        for (int i = 0; i < n; i++) {
            ss.insert(s[i]);
            string t = s[i];
            reverse(t.begin(), t.end());
            if (ss.find(t) != ss.end()) {
                ok = true;
            }
            if (t.size() != 3) {
                continue;
            }
            t.pop_back();
            if (ss.find(t) != ss.end()) {
                ok = true;
            }
        }
        ss.clear();
        for (int i = n - 1; i >= 0; i--) {
            ss.insert(s[i]);
            string t = s[i];
            if (t.size() != 3) {
                continue;
            }
            t.pop_back();
            reverse(t.begin(), t.end());
            if (ss.find(t) != ss.end()) {
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}