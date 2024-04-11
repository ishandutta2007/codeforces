#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res(n, 1);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < i)
            res[i] = 0;
        a[i] -= i * res[i];
        if (a[i] + i < n)
            res[a[i] + i] = 0;
    }
    for (auto i : res)
        cout << i << ' ';
    cout << '\n';
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