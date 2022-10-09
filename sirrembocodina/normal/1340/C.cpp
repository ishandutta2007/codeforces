
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    forn (i, m) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r, g;
    cin >> g >> r;
    deque<pair<int, int> > q;
    q.push_back({0, 0});
    vector<vector<int>> d(m, vector<int>(g + 1, 2e9));
    d[0][0] = 0;
    int ans = 2e18;
    while (!q.empty()) {
        int i = q.front().first, k = q.front().second;
        //cerr << a[i] << " " << k << " " << d[i][k] << endl;
        q.pop_front();
        if (i == m - 1) {
            ans = min(ans, d[i][k] * (r + g) + k);
        }
        if (k == g) {
            if (d[i][0] > d[i][k] + 1) {
                d[i][0] = d[i][k] + 1;
                q.push_back({i, 0});
            }
        }
        if (i > 0 && k + a[i] - a[i - 1] <= g) {
            if (d[i - 1][k + a[i] - a[i - 1]] > d[i][k]) {
                d[i - 1][k + a[i] - a[i - 1]] = d[i][k];
                q.push_front({i - 1, k + a[i] - a[i - 1]});
            }
        }
        if (i < m - 1 && k + a[i + 1] - a[i] <= g) {
            if (d[i + 1][k + a[i + 1] - a[i]] > d[i][k]) {
                d[i + 1][k + a[i + 1] - a[i]] = d[i][k];
                q.push_front({i + 1, k + a[i + 1] - a[i]});
            }
        }
    }
    if (ans == 2e18) {
        ans = -1;
    }
    cout << ans << endl;
}