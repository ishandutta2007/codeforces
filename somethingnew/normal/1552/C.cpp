#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
using namespace std;
bool cp(pair<int, int> a, pair<int, int> b) {
    if (a > b)
        swap(a, b);
    return (a.second > b.first and a.second < b.second);
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> seg2(k);
    vector<int> ex(n * 2, 1);
    for (int i = 0; i < k; ++i) {
        cin >> seg2[i].first >> seg2[i].second;
        if (seg2[i].first > seg2[i].second)
            swap(seg2[i].first, seg2[i].second);
        ex[seg2[i].first-1] = 0;
        ex[seg2[i].second-1] = 0;
    }
    vector<int> c;
    for (int i = 0; i < n * 2; ++i) {
        if (ex[i])
            c.push_back(i);
    }
    sort(all(c));
    for (int i = 0; i * 2 < c.size(); ++i) {
        seg2.push_back({c[i]+1, c[i + c.size() / 2]+1});
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            res += cp(seg2[i], seg2[j]);
        }
    }
    cout << res << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}