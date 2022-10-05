#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    cout << a[0] + a[1] << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}