#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "stack"

#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
void solve(){
    int n, m;
    cin >> n >> m;
    int f = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        f += a[i].first + m;
        f -= a[i].second;
        int l = max(0ll, m - a[i].second), r = min(m, a[i].first);
        a[i] = {l, r};
        f -= l * 2;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (f > 0) {
            ans[i] = min(f / 2, a[i].second - a[i].first);
            f -= 2 * ans[i];
        }
    }
    cout << abs(f) << '\n';
    for (int i = 0; i < n; ++i) {
        int x = a[i].first + ans[i];
        cout << x << ' ' << m - x << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}