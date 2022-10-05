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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    map<int, int> cnt;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
        while (cnt[a[i]] and b[ind] == a[i]) {
            ind++;
            cnt[a[i]]--;
        }
    }
    if (ind == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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