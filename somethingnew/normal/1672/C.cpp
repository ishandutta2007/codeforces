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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int frst = -1;
    int lst = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            if (frst == -1)
                frst = i;
            lst = i;
        }
    }
    if (lst == frst) {
        cout << "0\n";
        return;
    }
    cout << max(1, lst - frst - 1) << '\n';
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