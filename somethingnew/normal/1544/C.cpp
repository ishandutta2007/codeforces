#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
//#define int long long
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
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    reverse(all(b));
    vector<int> prefsumb(n + 1);
    for (int i = 0; i < n; ++i) {
        prefsumb[i + 1] = prefsumb[i] + b[i];
    }
    vector<int> suffsuma(n + 1);
    for (int i = 0; i < n; ++i) {
        suffsuma[i + 1] = suffsuma[i] + a[i];
    }
    for (int k = 0;; ++k) {
        int t = n + k - (n + k) / 4;
        int val = 0;
        val = suffsuma[max(t - k, 0)];
        val += k * 100;
        int ilyaval = prefsumb[min(t, n)];
        //cout << t << ' ' << val << ' ' << ilyaval << endl;
        if (val >= ilyaval) {
            cout << k << '\n';
            return;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
        solve();
}