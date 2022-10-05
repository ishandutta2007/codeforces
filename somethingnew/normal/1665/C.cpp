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
    vector<int> pred(n+1);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        pred[x]++;
    }
    pred.back() = 1;
    sort(all(pred));
    reverse(all(pred));
    while (pred.back() == 0)
        pred.pop_back();
    int l = pred.size() - 1, r = n;
    n = pred.size();
    while (l + 1 < r) {
        int m = l + r >> 1;
        int msht = m - n;
        for (int i = 0; i < n; ++i) {
            msht -= max(0, pred[i] + i - m);
        }
        if (msht >= 0)
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
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