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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1) {
        cout << "YES\n";
        return;
    }
    if (a[1] != 1 and a[0] != 1) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i-1]+1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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