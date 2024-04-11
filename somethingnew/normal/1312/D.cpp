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
#define int long long
using namespace std;
int mod = 998244353;
const int maxfac = 600000;
int fac[maxfac];
int pw(int a, int b){
    int res = 1;
    while(b){
        if(b%2) {res *= a; res %= mod;}
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
void makefac(){
    fac[0] = 1;
    for (int i = 1; i < maxfac; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
}
int inv(int x){
    return pw(x, mod - 2);
}
int cnk(int n, int k){
    if(k > n)
        return 0;
    if(k < 0)
        return 0;
    return fac[n] * inv(fac[k]) % mod * inv(fac[n-k]) % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    makefac();
    int n, m;
    cin >> n >> m;
    if(n == 2){
        cout << 0;
        return 0;
    }
    int ans = m * cnk(m - 1, n-2) % mod * pw(2, n - 2) % mod;
    for (int i = 1; i <= m; ++i) {
        ans -= cnk(i-1, n - 2) * pw(2, n - 2) % mod;
        ans %= mod;
    }
    ans += mod;
    ans *= inv(2);
    ans %= mod;
    cout << ans;
}