#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
    }
    sort(all(a));
    while (cnt) {
        a.back() *= 2;
        cnt--;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i];
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}