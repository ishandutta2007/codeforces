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

using namespace std;
#define int long long
vector<int> fact;
vector<int> invfact;
bool predfact;
const int MOD = 1000000007;

int pow(int a, int b, int mod = MOD){
    int res = 1;
    while(b){
        if(b%2) {res *= a;if(mod) res %= mod;}
        a *= a;
        if(mod) a %= mod;
        b /= 2;
    }
    return res;
}

int inv(int x, int mod = MOD){
    return pow(x, mod-2, mod);
}

int calc_c(int n, int k, int mod = MOD){
    if(predfact){
        long long res = fact[n] * invfact[k] % mod * invfact[n-k] % mod;
        return (int)res;
    } else{
        int res = 1;
        int invres = 1;
        for (int i = n - k + 1; i <= n; ++i) {
            res *= i;
            res %= mod;
        }
        for (int i = 1; i <= k; ++i) {
            invres *= i;
            invres %= mod;
        }
        return (int)(1ll * res * inv(invres) % mod);
    }
}

void allfact(int n, int mod = MOD){
    predfact = true;
    int fc = 1;
    fact.push_back(1);
    invfact.push_back(1);
    for (int i = 1; i <= n; ++i) {
        fc *= i;
        fc %= mod;
        fact.push_back(fc);
        invfact.push_back(inv(fc));
    }
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    int r = 0;
    int res = 0;
    for (int l = 0; l < n; ++l) {
        while(r < n and a[l] + k >= a[r])
            r++;
        //cout << l << ' ' << r << endl;
        int t = r - l;
        if(t >= m) {
            res += calc_c(t - 1, m - 1);
            //cout << "AAAA";
        }res %= MOD;
    }
    cout << res << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int t;
    allfact(300000);
    cin >> t;
    while(t--){
        solve();
    }
}