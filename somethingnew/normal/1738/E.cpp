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
int fac[100005], invfac[100005];
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pw(x, mod - 2);
}
int cnk(int n, int k) {
    return fac[n] * invfac[n - k] % mod * invfac[k] % mod;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = 1;
    a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    n = n + 2;
    int r = n - 1;
    vector<pair<int, int>> goodpairs;
    int sm = 0;
    for (int l = 0; l < n; ++l) {
        if (a[l] == 0)
            continue;
        sm += a[l];
        while (sm > 0 and r >= l) {
            sm -= a[r];
            r--;
        }
        if (r < l)
            break;
        if (sm != 0)
            continue;
        goodpairs.push_back({l, r});
    }
    int cntvl = 1;
    int ans = 0;
    int tomlt = 0;
    for (auto [l, r] : goodpairs) {
        int zerkill = 0;
        int zl = 0, zr = 0;
        for (int i = l + 1; i <= r; ++i) {
            if (a[i] == 0)
                zl++;
            else
                break;
        }
        for (int i = r; i > l; --i) {
            if (a[i] == 0)
                zr++;
            else
                break;
        }
        if (zl == r - l and zl != 0) {
            //cerr << "BEb";
            if (l == 0)
                zerkill = pw(2, zl - 1);
            else {
                for (int i = 0; i <= zl; ++i) {
                    zerkill += cnk(zl + 1, i + 1);
                }
            }
        } else {
            if (l == 0) {
                for (int i = 0; i <= min(zl, zr); ++i) {
                    zerkill += cnk(zl, i) * cnk(zr, i) % mod;
                }
            } else {
                for (int i = 0; i <= min(zl, zr); ++i) {
                    zerkill += cnk(zl + 1, i + 1) * cnk(zr + 1, i + 1) % mod;
                }
            }
        }
        //cerr << l << ' ' << r << ' ' << cntvl << '\n';
        //cerr << zl << ' ' << zr << ' ' << zerkill % mod << '\n';
        zerkill %= mod;
        ans += cntvl * zerkill % mod;
        cntvl *= (zerkill + tomlt);
        cntvl %= mod;
        if (tomlt == 0)
            tomlt = 1;
    }
    cout << ans % mod << '\n';
}
signed main() {
    fac[0] = 1;
    invfac[0] = 1;
    for (int i = 1; i < 100005; ++i) {
        fac[i] = i * fac[i - 1] % mod;
        invfac[i] = inv(fac[i]);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}