#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2 == 1) {
        for (auto &i : s) i = '0' + '1' - i;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' and k != 0) {
            ans[i] = 1;
            k--;
            s[i] = '1';
        }
    }
    ans.back() += k;
    if (k % 2 == 1)
        s.back() = '0' + '1' - s.back();
    cout << s << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}