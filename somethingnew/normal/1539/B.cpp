#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        a[i + 1] = a[i];
        char c;
        cin >> c;
        a[i + 1][c - 'a']++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<int> c = a[r];
        for (int i = 0; i < 26; ++i) {
            c[i] -= a[l][i];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += c[i] * (i + 1);
        }
        cout << res << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
    int n = 1;
    while (n--)
        solve();
}