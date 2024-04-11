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
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string s2 = s;
    reverse(all(s2));
    if (s2 == s) {
        cout << "1\n";
        return;
    }
    if (k == 0) {
        cout << "1\n";
        return;
    }
    cout << 2 << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}