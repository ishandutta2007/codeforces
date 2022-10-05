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
int mod = 1e9 + 7;
int pw(int a, int b) {
    int res = 1;
    while (b != 0) {
        if (b & 1)
            res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}
int inv(int a) {
    return pw(a, mod - 2);
}
vector<int> fac;
vector<int> invfac;
int MAXN = 5e5;
int cnk(int n, int k) {
    return fac[n] * invfac[k] % mod * invfac[n-k] % mod;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fac.assign(MAXN, 1);
    invfac.assign(MAXN, 1);
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = inv(fac[i]);
    }
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    if (a[0] == -1) {
        cout << "0\n";
        return 0;
    }
    a.push_back(-1);
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        if (a[i] == -1)
            continue;
        res += cnk(a[i] + i, i) % mod;
        for (int j = a[i]; j > a[i + 1]; --j) {
            res += cnk(j + i, i) % mod;
        }
        //cerr << a[i] + i << ' ' << i << '\n';

    }
    cout << (res + mod - 1) % mod << '\n';
}