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
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n + m; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cout << n + m - a.size() << '\n';
}
signed main() {
   int n;
   cin >> n;
   while (n--) solve();
}