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
    string s;
    cin >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) {
            cout << i + 1 << ' ' << i + 2 << '\n';
            return;
        }
    }
    cout << "-1 -1\n";
    return;
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}