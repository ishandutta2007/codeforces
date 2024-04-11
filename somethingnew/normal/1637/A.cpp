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
    vector<int> a(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b = a;
    sort(all(b));
    if (b != a)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}