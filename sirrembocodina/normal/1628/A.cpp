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
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        vector<int> suf(n + 1);
        set<int> s;
        for (int i = 0; i <= n; i++) {
            s.insert(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            s.erase(a[i]);
            suf[i] = *s.begin();
        }
        vector<int> ans;
        int cur = 0;
        while (cur < n) {
            int x = suf[cur];
            ans.push_back(x);
            if (x == 0) {
                cur++;
                continue;
            }
            vector<bool> was(x);
            int cnt = 0;
            while (cnt < x) {
                if (a[cur] < x && !was[a[cur]]) {
                    was[a[cur]] = true;
                    cnt++;
                }
                cur++;
            }
        }
        cout << ans.size() << '\n';
        for (int x: ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}