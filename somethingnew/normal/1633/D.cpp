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
vector<int> cnt(2001, 1e9);
int mx = 0;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(min(mx * n + 1, k + 1), 0);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int vl = cnt[b[i]], c;
        cin >> c;
        //cout << vl << '\n';
        for (int j = (int)a.size(); j >= 0; --j) {
            if (j + vl >= a.size())
                continue;
            a[j + vl] = max(a[j] + c, a[j + vl]);
            res = max(res, a[j + vl]);
        }
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cnt[1] = 0;
    for (int i = 1; i < 1001; ++i) {
        mx = max(mx, cnt[i]);
        for (int x = 1; x <= i; ++x) {
            cnt[i + i/x] = min(cnt[i + i/x], cnt[i] + 1);
        }
    }
    int t = 1;
    cin >> t;
    while (t--) solve();
}