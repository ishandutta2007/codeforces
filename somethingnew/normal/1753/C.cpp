//        
//   @roadfromroi 
//        
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
#define int long long
int mod = 998244353;

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pw(x, mod - 2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt += a[i];
    }
    int cnt2 = 0;
    for (int i = 0; i < n - cnt; ++i) {
        cnt2 += a[i];
    }
    int res = 0;
    for (int i = 0; i < cnt2; ++i) {
        res += (n * (n - 1) % mod * inv(2 * (cnt2 - i) * (cnt2 - i) % mod)) % mod;
    }
    cout << res % mod << '\n';
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