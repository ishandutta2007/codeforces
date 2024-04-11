#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long

void solve() {
    int n, n1;
    cin >> n;
    n1 = n;
    int st = 1;
    while (n % 2 == 0) {
        n /= 2;
        st *= 2;
    }
    int t = min(st * 2, n);
    if (t == 1) {
        cout << "-1\n";
        return;
    }
    if (t * (t + 1) / 2 > n1)
        cout << "-1\n";
    else
        cout << min(st * 2, n) << '\n';

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}