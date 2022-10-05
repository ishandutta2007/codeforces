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
#include <immintrin.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x %= 2;
    y %= 2;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        x ^= a;
    }
    if (x % 2 == y)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}