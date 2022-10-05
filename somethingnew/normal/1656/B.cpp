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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp[k + a[i]]) {
            res = 1;
        }
        if (mp[a[i]-k]) {
            res = 1;
        }
        mp[a[i]] = 1;
    }
    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
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