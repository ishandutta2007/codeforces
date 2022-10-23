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
int pw(int a, int k) {
    int res = 1;
    while (k) {
        if (k % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        k /= 2;
    }
    return res;
}
int inv(int a) {
    return pw(a, mod - 2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> res(n);
    vector<int> sufsm(n + 2, 0);
    res[n - 1] = pw(inv(2), (n - 1) / 2);
    sufsm[n - 1] = res[n - 1];
    int t = n;
    for (int i = n - 2; i >= 1; --i) {
        res[i] = pw(inv(2), (i + 2) / 2);
        //res[i] -= sufsm[i + 1];
        while ((t + 1) / 2 > i)
            t--;
        //cerr << res[i] << '\n';
        //cerr << t << ' ' << i << ' ' << res[i] << ' ' << sufsm[t + 1] << '\n';
        res[i] *= (1 + mod - sufsm[t + 1]);
        res[i] %= mod;
        sufsm[i] = sufsm[i + 1] + res[i];
        if (sufsm[i] >= mod)
            sufsm[i] -= mod;
    }
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += res[i];
        cout << res[i] << '\n';
    }
    //cerr << sm % mod << '\n';
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