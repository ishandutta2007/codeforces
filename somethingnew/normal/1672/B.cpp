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
    string s;
    cin >> s;
    int cnt = 0;
    if (s.back() == 'A') {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A')
            cnt++;
        else
            cnt--;
        if (cnt < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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