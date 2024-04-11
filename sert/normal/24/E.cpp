#include <bits/stdc++.h>
using namespace std;

double INF = 1e12;

double solve(const vector<pair<int, int>> &a) {
    if (a.empty() || a[0].second < 0 || a.back().second >= 0) return INF;
    double L = 0;
    double R = INF;
    for (int i = 0; i < 70; i++) {
        double M = (L + R) * 0.5;
        double maxPos = a[0].first;
        double minNeg = a.back().first;
        for (auto &[x, v] : a) {
            if (v >= 0) maxPos = max(maxPos, x + M * v);
            else minNeg = min(minNeg, x + M * v);
        }
        if (maxPos >= minNeg) R = M;
        else L = M;
    }
    return (L + R) * 0.5;
}

void solve() {
    int n;
    cin >> n;
    double ans = INF;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        if (!a.empty() && a.back().second < 0 && v >= 0) {
            ans = min(ans, solve(a));
            a.clear();
        }
        a.emplace_back(x, v);
    }
    ans = min(ans, solve(a));
    if (ans > INF * 0.9) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    cout.precision(12);
    cout << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 2;
#endif
    while (t--) {
        solve();
    }
}