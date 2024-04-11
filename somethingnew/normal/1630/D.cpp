#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int gc = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        gc = gcd(gc, x);
    }
    vector<vector<int>> b(gc);
    vector<int> cnt(gc);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        b[i % (gc)].push_back(abs(a[i]));
        if (a[i] < 0)
            cnt[i % (gc)]++;
        res += abs(a[i]);
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < gc; ++i) {
        sort(all(b[i]));
        if (cnt[i] % 2 == 1)
            a1 += b[i][0];
        else
            a2 += b[i][0];
    }
    cout << res - 2 * min(a1, a2) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}