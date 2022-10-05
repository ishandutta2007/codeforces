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
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < l; ++i) {
        int k;
        cin >> k;
        k--;
        a[k]++;
    }
    for (int i = 0; i < r; ++i) {
        int k;
        cin >> k;
        k--;
        a[k]--;
    }
    int s = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        s2 += abs(a[i]);
    }
    if (s < 0) {
        s *= -1;
        for (int i = 0; i < n; ++i) {
            a[i] *= -1;
        }
    }
    int res = 0, tt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0)
            tt += a[i] / 2;
    }
    res = s2 / 2 + max(0ll, s / 2 - tt);
    cout << res << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}