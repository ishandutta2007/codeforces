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
    string s;
    cin >> s;
    char t = '0';
    for (int i = 0; i < s.size(); ++i) {
        t = max(t, s[i]);
    }
    cout << t << '\n';
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