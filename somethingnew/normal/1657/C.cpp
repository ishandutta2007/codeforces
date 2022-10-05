#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    reverse(all(s));
    int op = 0;
    while (s.size() > 1) {
        if (s.back() == '(') {
            op++;
            s.pop_back();
            s.pop_back();
            continue;
        }
        int i = -1;
        for (i = s.size() - 2; i >= 0; --i) {
            if (s[i] == ')')
                break;
        }
        if (i == -1) {
            break;
        }
        op++;
        while (s.size() != i)
            s.pop_back();
    }
    cout << op << ' ' << s.size() << '\n';
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