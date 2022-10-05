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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> stud(n);
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> stud[i];
    }
    sort(all(stud));
    for (int i = 0; i + 1 < n; ++i) {
        // x = 1
        // 1 3
        b.push_back(max(0ll, (stud[i + 1] - stud[i] - 1) / x));
    }
    sort(all(b));
    int res = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (k >= b[i]) {
            k -= b[i];
            res++;
        } else {
            break;
        }
    }
    cout << n - res << '\n';
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