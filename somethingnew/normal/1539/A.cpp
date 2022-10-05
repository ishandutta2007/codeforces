#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n, x, t;
    cin >> n >> x >> t;
    int res = 0;
    if (t >= (n - 1) * x) {
        cout << (n - 1) * (n) / 2 << '\n';
        return;
    }
    int q = t / x;
    res = (n - q) * q;
    res += q * (q - 1) / 2;
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
    int n;
    cin >> n;
    while (n--)
        solve();
}