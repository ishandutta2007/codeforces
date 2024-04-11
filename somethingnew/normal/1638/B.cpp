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
using namespace std;
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int nc = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        x = a[i];
        if (x % 2 == 0) {
            if (x < c) {
                cout << "NO\n";
                return;
            }
            c = x;
        } else {
            if (x < nc) {
                cout << "NO\n";
                return;
            }
            nc = x;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}