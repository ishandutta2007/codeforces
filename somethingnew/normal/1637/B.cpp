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
#define int long long
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += (1 + (x == 0)) * (i + 1) * (n - i);
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}