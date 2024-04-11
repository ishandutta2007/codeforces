#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

/*pair<string, vector<int>> solve(int l, int r) {
    if (r - l == 1) {
        return vector<int>(1, 0);
    }
    int mid = (l + r) / 2;
    vector<int> a = solve(l, mid);
    vector<int> b = solve(mid, r);
    vector<pair<pair<int, int>
}*/

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        n = 1 << k;
        string s;
        cin >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            x[i] = s[i] - 'a';
        }
        int ans = -1;
        for (int len = 0; len < k; len++) {
            vector<pair<pair<int, int>, int>> y(n);
            for (int i = 0; i < n; i++) {
                if ((i & (1 << len)) == 0) {
                    y[i] = {{x[i], x[i + (1 << len)]}, i};
                } else {
                    y[i] = {{x[i], x[i - (1 << len)]}, i};
                }
            }
            sort(y.begin(), y.end());
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (i > 0 && y[i].first != y[i - 1].first) {
                    cur++;
                }
                x[y[i].second] = cur;
            }
            ans = y[0].second;
        }
        for (int i = 0; i < n; i++) {
            cout << s[i ^ ans];
        }
        cout << '\n';
    }
    return 0;
}