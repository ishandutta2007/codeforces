#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int mod = 998244353;

int get_f(string& s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1; i < n; ++i) {
        int cur = f[i];
        while (cur > 0 && s[cur] != s[i]) {
            cur = f[cur];
        }
        if (s[cur] == s[i]) {
            ++cur;
        }
        f[i + 1] = cur;
    }
    return f.back();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        string s;
        cin >> s;
        int n = s.size();
        int len = 0;
        forn (i, n) {
            if (s[i] != s[s.size() - 1 - i]) {
                break;
            }
            len++;
        }
        if (len == n) {
            cout << s << endl;
            continue;
        }

        string ns = s.substr(len, n - len * 2);
        string rs = "";
        forn (i, ns.size()) {
            rs += ns[ns.size() - 1 - i];
        }

        string t = ns + "#" + rs;
        int f1 = get_f(t);
        //cerr << t << endl;
        t = rs + "#" + ns;
        int f2 = get_f(t);
        //cerr << t << endl;
        //cerr << f1 << " " << f2 << endl;

        string ans = "";
        forn (i, len) {
            ans += s[i];
        }
        if (f1 > f2) {
            forn (i, f1) {
                ans += s[len + i];
            }
        } else {
            forn (i, f2) {
                ans += s[n - len - f2 + i];
            }
        }
        forn (i, len) {
            ans += s[s.size() - len + i];
        }
        cout << ans << endl;
    }
}