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
#include "queue"

using namespace std;

typedef long long ll;
typedef long double ld;
int a1 = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int mn = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[mn])
            mn = i;
    }
    cout << n - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        if (i != mn)
            cout << mn + 1 << ' ' << i + 1 << ' ' << a[mn] << ' ' << a1 + 2 * (i % 2) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}