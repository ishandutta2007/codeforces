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
#define all(x) x.begin(), x.end()
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(all(b));
    int seg = 1e9 + 3;
    int l = 0, r = 1e9 + 3;
    int rg = 0;
    int trg = (n + k + 1) / 2;
    for (int lg = 0; lg + trg <= n; ++lg) {
        while (rg < lg + trg) {
            rg++;
        }
        if (b[rg - 1] - b[lg] < seg) {
            seg = b[rg-1] -b[lg];
            l = b[lg];
            r = b[rg - 1];
        }
    }
    cout << l << ' ' << r << '\n';
    int lka = 1;
    int viv = 0;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        if (viv == k - 1) {
            cout << lka << ' ' << n << '\n';
            break;
        }
        if (l <= a[i] and a[i] <= r)
            val++;
        else
            val--;
        if (val > 0) {
            cout << lka << ' ' << i + 1 << '\n';
            lka = i + 2;
            val = 0;
            viv++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}