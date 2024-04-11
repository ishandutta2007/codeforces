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
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int mod = 998244353;
int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pow(x, mod - 2);
}
long long cnk(int n, int k) {
    long long res = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        res *= i;
        res %= mod;
    }
    int res2 = 1;
    for (int j = 1; j <= k; ++j) {
        res2 *= j;
        res2 %= mod;
    }
    return res * inv(res2) % mod;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cn = 0, k = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 != s.size() and s[i] == '1' and s[i + 1] == '1') {
            i++;
            cn++;
            k++;
        } else {
            if (s[i] != '1')
                cn++;
        }
    }
    //cout << cn << ' ' << k << ' ';
    cout << cnk(cn, k) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}