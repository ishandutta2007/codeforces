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
#define int long long
void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << '\n';
        }
        return;
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n / 2; ++i) {
        int t = i * 2 * k + 1;
        for (int j = 0; j < k; ++j) {
            cout << t + j * 2 << ' ';
        }
        cout << '\n';
        for (int j = 0; j < k; ++j) {
            cout << t + j * 2 + 1 << ' ';
        }
        cout << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}