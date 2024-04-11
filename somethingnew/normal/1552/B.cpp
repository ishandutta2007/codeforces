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
bool bolsh(vector<int> a, vector<int> b) {
    int c = 0;
    for (int i = 0; i < 5; ++i) {
        c += a[i] > b[i];
    }
    return (c < 3);
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j;
    auto aba = a[0];
    for (int i = 1; i < n; ++i) {
        if (bolsh(a[i], aba))
            aba = a[i];
    }
    bool ok = 1;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (aba != a[i])
            ok &= bolsh(aba, a[i]);
        else
            ind = i;
    }
    if (ok)
        cout << ind + 1 << '\n';
    else
        cout << "-1\n";
}
signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
5
10 5 7 6 8
0 5 22 45 79
 */