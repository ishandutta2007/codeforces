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
vector<int> mt(64);
void solve() {
    int x;
    cin >> x;
    if (x % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> a;
    for (int i = 57; i >= 0; --i) {
        while (x >= mt[i]) {
            x -= mt[i];
            a.push_back(1);
            for (int j = 0; j < i; ++j) {
                a.push_back(0);
            }
        }
    }
    cout << a.size() << '\n';
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    for (int i = 0; i < 64; ++i) {
        int res = i + 1;
        for (int j = 0; j <= i; ++j) {
            res += (j + 1) * (1ll << (i - j));
        }
        mt[i] = res;
    }
    int n;
    cin >> n;
    while (n--) solve();
}