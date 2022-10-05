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

void solve() {
    string s;
    cin >> s;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2) {
            if (s[i] == '1')
                d1++;
            if (s[i] == '?'){
                d1++;d2++;
            }
            if (s[i] == '0') {
                d2++;
            }
        } else {
            if (s[i] == '0')
                d1++;
            if (s[i] == '?'){
                d1++;d2++;
            }
            if (s[i] == '1') {
                d2++;
            }
        }
        if (max(d1, d2) > 5) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << 10 << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}