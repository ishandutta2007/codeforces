#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
//#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pole(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        if (i == 0 or pole[i - 1][0] == 0)
            pole[i][0] = 1;
    }
    for (int i = 2; i < m; ++i) {
        if (pole[n - 1][i - 1] == 0)
            pole[n - 1][i] = 1;
    }
    for (int i = n - 3; i >= 0; --i) {
        if (pole[i + 1][m - 1] == 0)
            pole[i][m - 1] = 1;
    }
    for (int i = m - 3; i >= 2; --i) {
        if (pole[0][i + 1] == 0)
            pole[0][i] = 1;
    }
    for (auto i : pole) {
        for (auto j : i) {
            cout << j;
        }
        cout << '\n';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
        solve();
}