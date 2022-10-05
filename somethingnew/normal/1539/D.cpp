#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> twr(n);
    for (int i = 0; i < n; ++i) {
        cin >> twr[i].second >> twr[i].first;
    }
    sort(all(twr));
    int res = 0;
    int byed = 0;
    int lind = 0, rind = twr.size() - 1;
    while (lind <= rind) {
        if (byed >= twr[lind].first) {
            byed += twr[lind].second;
            res += twr[lind].second;
            lind++;
        } else {
            int tr = twr[lind].first - byed;
            int kup = min(tr, twr[rind].second);
            res += kup * 2;
            byed += kup;
            twr[rind].second -= kup;
            if (twr[rind].second == 0)
                rind--;
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
    int n = 1;
    while (n--)
        solve();
}