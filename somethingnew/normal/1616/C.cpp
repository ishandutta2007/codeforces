#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int delt = (a[j] - a[i]);
            int shag = j - i;
            int de = gcd(delt, shag);
            delt /= de;
            shag /= de;
            int re = 0;
            for (int t = i % shag; t < n; t += shag) {
                if (a[t] - (t-i) / shag * delt == a[i])
                    re++;
            }
            res = max(res, re);
        }
    }
    cout << n - res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}