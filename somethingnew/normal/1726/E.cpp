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
bool goodperm(vector<int> p) {
    vector<int> pmn(p.size());
    for (int i = 0; i < p.size(); ++i) {
        pmn[p[i]] = i;
    }
    for (int i = 0; i < p.size(); ++i) {
        if (abs(pmn[i] - p[i]) > 1) {
            return 0;
        }
        //if (abs(pmn[i] - p[i]) == 0) {
        //    return 0;
        //}
    }
    return 1;
}
void gena(int n) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    int res = 0;
    do {
        if (goodperm(p)) {
            res++;
            //for (auto i : p)
            //    cout << i << ' ';
            //cout << '\n';
        }
    } while (next_permutation(all(p)));
    cout << res << ' ';
}
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int a) {
    return pw(a, mod - 2);
}
vector<int> fac;
vector<int> invfac;
int cnk(int n, int k) {
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}
void solve(int n) {
    vector<int> pr(n + 1, 1); // pr[n] = how to make n pairs
    for (int i = 1; i < pr.size(); ++i) {
        pr[i] = pr[i - 1] * (i * 2 - 1) % mod;
    }
    vector<int> goodpr(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        goodpr[i] = (goodpr[i - 1] + goodpr[i - 2] * (i - 1)) % mod;
    }
    int res = 0;
    for (int i = 0; i <= n; i += 4) {
        res += pw(2, i / 4) * cnk(n - i / 2, i / 2) % mod * pr[i / 4] % mod * goodpr[n - i] % mod;
        //cerr << res % mod << '\n';

    }
    cout << res % mod << '\n';
}
signed main() {
    int maxn = 4e5;
    fac.assign(maxn, 1);
    invfac = fac;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = inv(fac[i]);
    }
    for (int i = 1; i < 9; ++i) {
       // gena(i);
        //solve(i);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}