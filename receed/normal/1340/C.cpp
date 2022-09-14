#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 10001, M = 1001;
ll dp[N][M], used[N][M], d[N], inf = 1e9;
ll n, m, g, r;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i, m)
        cin >> d[i];
    sort(d, d + m);
    cin >> g >> r;
    rep(i, m)
        rep(j, g + 1)
            dp[i][j] = (i + j == 0 ? 0 : inf);
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while (!q.empty()) {
        int cx = q[0].first, cy = q[0].second;
        q.pop_front();
        if (used[cx][cy])
            continue;
        used[cx][cy] = 1;
        if (cx > 0) {
            ll nd = cy + d[cx] - d[cx - 1];
            if (nd <= g && dp[cx - 1][nd] > dp[cx][cy]) {
                dp[cx - 1][nd] = dp[cx][cy];
                q.push_front({cx - 1, nd});
            }
            if (nd == g && dp[cx - 1][0] > dp[cx][cy] + 1) {
                dp[cx - 1][0] = dp[cx][cy] + 1;
                q.push_back({cx - 1, 0});
            }
        }
        if (cx < m - 1) {
            ll nd = cy + d[cx + 1] - d[cx];
            if (nd <= g && dp[cx + 1][nd] > dp[cx][cy]) {
                dp[cx + 1][nd] = dp[cx][cy];
                q.push_front({cx + 1, nd});
            }
            if (nd == g && dp[cx + 1][0] > dp[cx][cy] + 1) {
                dp[cx + 1][0] = dp[cx][cy] + 1;
                q.push_back({cx + 1, 0});
            }
        }
    }
    ll ans = inf;
    rep(i, g + 1)
        ans = min(ans, dp[m - 1][i] * (r + g) + i);
    if (ans == inf)
        ans = -1;
    cout << ans;
}