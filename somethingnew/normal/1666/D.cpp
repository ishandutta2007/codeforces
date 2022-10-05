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
void NO() {
    cout << "NO\n";
}
void YES() {
    cout << "YES\n";
}
void solve() {
    string s, t;
    cin >> s >> t;
    string s2 = s, ans;
    for (int i = (int)t.size() - 1; i >= 0; --i) {
        int p = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == t[i])
                p = j;
        }
        if (p == -1) {
            return NO();
        }
        s[p] = '*';
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '*')
            ans.push_back(s2[i]);
    }
    if (ans == t) return YES();
    return NO();
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