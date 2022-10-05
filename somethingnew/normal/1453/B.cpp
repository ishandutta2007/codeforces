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
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i < n; ++i) {
        res += abs(a[i] - a[i-1]);
    }
    int ch = max(abs(a[0] - a[1]), abs(a.back() - a[n-2]));
    for (int i = 1; i < n - 1; ++i) {
        int ch2 = abs(a[i] - a[i-1]) + abs(a[i] - a[i + 1]);
        ch2 -= abs(a[i-1] - a[i + 1]);
        ch = max(ch, ch2);
    }
    res -= ch;
    cout << res << '\n';
}
signed main() {
   int n;
   cin >> n;
   while (n--) solve();
}