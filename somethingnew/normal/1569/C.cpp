#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int mod = 998244353;
int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pow(x, mod - 2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int mxcnt = 0, mxm1cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx)
            mxcnt += 1;
        if (a[i] == mx - 1)
            mxm1cnt++;
    }
    if (mxcnt != 1) {
        int fac = 1;
        for (int i = 2; i <= n; ++i) {
            fac *= i;
            fac %= mod;
        }
        cout << fac << '\n';
    } else {
        vector<int> fac(n + 1);
        fac[0] = 1;
        for (int i = 0; i < n; ++i) {
            fac[i + 1] = (i + 1) * fac[i] % mod;
        }
        int t = n - mxm1cnt - 1;
        int res = fac[n] * inv(fac[n - t]) % mod;
        res *= (fac[mxm1cnt + 1] - fac[mxm1cnt] + mod) % mod;
        res %= mod;
        cout << res << '\n';
    }
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}