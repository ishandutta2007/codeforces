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
    int n;
    cin >> n;
    int k;
    cin >> k;
    int mx = n - 1;
    if (k == mx and n == 4) {
        cout << "-1\n";
        return;
    }
    if (k == mx) {
        cout << mx << ' ' << mx - 1 << '\n';
        cout << n / 2 + 1 << ' ' << mx - (n / 2) << '\n';
        cout << mx - (n / 2 + 1) << ' ' << n / 2 << '\n';
        cout << 0 << " " << 1 << endl;
        for (int i = 0; i < n / 2; ++i) {
            if (i != 0 and i != 1 and i != mx - n / 2 and i != mx - n / 2 - 1) {
                cout << i << ' ' << mx - i << '\n';
            }
        }
        return;
    }
    if (k == 0) {
        for (int i = 0; i < n / 2; ++i) {
            cout << i << ' ' << mx - i << '\n';
        }
        return;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (i == 0)
            cout << 0 << ' ' << mx - k << '\n';
        else if (i == mx - k or i == k) {
            cout << k << ' ' << mx << '\n';
        } else {
            cout << i << ' ' << mx - i << '\n';
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