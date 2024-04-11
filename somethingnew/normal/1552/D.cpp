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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j < (1 << n); ++j) {
            int r1 = 0;
            int r2 = 0;
            if ((i & j) == 0) {
                for (int k = 0; k < n; ++k) {
                    if ((1 << k) & i) {
                        r1 += a[k];
                    }
                    if ((1 << k) & j) {
                        r2 += a[k];
                    }
                }
                if (r1 == r2) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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