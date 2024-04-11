#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
vector<vector<int>> slv(vector<pair<int, int>> segs, int l, int r) {
    if (segs.empty())
        return {{0, 0}, {0, 0}};
    vector<vector<int>> res(2, vector<int>(2));
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            int rnow = min((segs.back().first - l) * i, j * (r - segs[0].second));
            for (int k = 0; k + 1 < segs.size(); ++k) {
                rnow = min(rnow, (segs[k].first - l) * i + (r - segs[k + 1].second) * j);
            }
            res[i-1][j-1] = rnow;
        }
    }
    return res;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(m), segs2;
    vector<int> points(n);
    for (auto &i : points) {
        cin >> i;
    }
    for (auto &[l, r] : segs) {
        cin >> l >> r;
    }
    sort(all(points));
    sort(all(segs));
    int uk = 0;
    for (auto [l, r] : segs) {
        while (uk < n and points[uk] < l)
            uk++;
        if (uk < n and points[uk] <= r)
            continue;
        if (!segs2.empty() and segs2.back().first == l and segs2.back().second <= r)
            continue;
        while (!segs2.empty() and segs2.back().second >= r)
            segs2.pop_back();
        segs2.emplace_back(l, r);
    }
    segs.clear();
    vector<vector<pair<int, int>>> gpsegs(n + 1);
    uk = 0;
    for (auto [l, r] : segs2) {
        while (uk < n and points[uk] < l)
            uk++;
        gpsegs[uk].push_back({l, r});
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0] = slv(gpsegs[0], -1e16, points[0])[0];
    points.push_back(1e16);
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> move = slv(gpsegs[i + 1], points[i], points[i + 1]);
        dp[i + 1][0] = min(dp[i][0] + move[1][0], dp[i][1] + move[0][0]);
        dp[i + 1][1] = min(dp[i][0] + move[1][1], dp[i][1] + move[0][1]);
    }
    cout << min(dp.back()[0], dp.back()[1]) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int nn;
    cin >> nn;
    for (int i = 0; i < nn; ++i) {
        solve();
    }
}