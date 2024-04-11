#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;
int mod = 998244353;
vector<int> a;
vector<int> dp;
vector<int> deli;
int slv(int v, int x) {
    if (v == -1)
        return 0;
    x = a[v] / ((a[v] + x - 1) / x);
    long long t = 0;
    if (v != 0) {
        t = ((long long)a[v-1] - 1ll) / x * v % mod;
    }
    if (deli[v] != x) {
        deli[v] = x;
        dp[v] = 0;
        dp[v] = (slv(v - 1, x) + t) % mod + 1;
    }
    //cout << v << ' ' << x << ' ' << dp[v][x] - 1 << endl;
    return dp[v] - 1;
}
void solve(){
    int n;
    cin >> n;
    a.assign(n, {});
    deli.assign(n, -1);
    dp.assign(n, {});
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        //cerr << slv(i, a[i]) << endl;
        res += slv(i, a[i]);
    }
    cout << res % mod << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}