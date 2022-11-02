#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n;
    cin >> n;
    vector<int> len;
    while (n) {
        int x = 2;
        while ((x + 1) * (x) / 2 <= n) x++;
        len.push_back(x);
        n -= x * (x - 1) / 2;
    }
    sort(all(len));
    for (int i = (int)len.size() - 1; i >= 1; i--)
        len[i] -= len[i - 1];
    cout << 1;
    for (auto i : len) {
        while (i--) {
            cout << 3;
        }
        cout << 7;
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}