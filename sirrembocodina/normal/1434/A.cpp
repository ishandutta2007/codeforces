#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n = 6, m;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    vector<pair<int, int>> c;
    forn (i, m) {
        cin >> b[i];
        forn (j, n) {
            c.push_back({b[i] - a[j], i});
        }
    }
    sort(c.begin(), c.end());
    vector<int> cnt(m);
    int cnt_all = 0;
    int r = 0;
    int ans = 2e18;
    forn (l, c.size()) {
        while (r < c.size() && cnt_all < m) {
            if (cnt[c[r].second] == 0) {
                cnt_all++;
            }
            cnt[c[r].second]++;
            r++;
        }
        if (cnt_all < m) {
            break;
        }
        ans = min(ans, c[r - 1].first - c[l].first);
        cnt[c[l].second]--;
        if (cnt[c[l].second] == 0) {
            cnt_all--;
        }
    }
    cout << ans << endl;
}