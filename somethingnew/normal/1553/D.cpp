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
    string s, t;
    cin >> s >> t;
    while (!s.empty()) {
        if (s.back() == t.back()) {
            s.pop_back();
            t.pop_back();
            if (t.empty()) {
                cout << "YES\n";
                return;
            }
        } else {
            s.pop_back();
            if (!s.empty())
                s.pop_back();
        }
    }
    cout << "NO\n";
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}