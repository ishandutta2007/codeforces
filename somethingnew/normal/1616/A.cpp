#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[abs(x)]++;
    }
    int res = 0;
    for (auto i : cnt) {
        res += min(i.second, 2ll - (i.first == 0));
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}