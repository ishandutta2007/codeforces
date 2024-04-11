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
    int res = 0;
    int n, x;
    cin >> n >> x;
    vector<int> a(n), ex(n + 1, 1);
    ex[n] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int trg = 0;
    for (int i = 0; i < n; ++i) {
        if (ex[i] == 0)
            continue;
        while (trg != n and (a[trg] < a[i] * x or ex[trg] == 0)) {
            trg++;
        }
        if (ex[trg] and a[trg] == a[i] * x) {
            ex[trg] = 0;
        } else {
            res++;
        }
    }
    cout << res << '\n';
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