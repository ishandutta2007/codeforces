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

using namespace std;
int gtval(int x, int y) {
    return (x == 0) or (y == 0);
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        x >>= 1;
        y >>= 1;
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> vv(2, vector<int>(2));
        for (int j = i + 1; j < n; ++j) {
            int x1 = abs(a[i].first - a[j].first) & 1;
            int y1 = abs(a[i].second - a[j].second) & 1;
            for (int x2 = 0; x2 < 2; ++x2) {
                for (int y2 = 0; y2 < 2; ++y2) {
                    int rk = gtval(x1, y1) + gtval(x2, y2) + gtval((x1 + x2) & 1, (y1 + y2) & 1);
                    if (rk & 1)
                        res += vv[x2][y2];
                }
            }
            vv[x1][y1]++;
        }
    }
    cout << res << '\n';
}