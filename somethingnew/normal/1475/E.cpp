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
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
ll pow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b % 2){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
ll inv(ll x){
    return pow(x, mod - 2);
}
ll cnk(int n, int k){
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        res *= i;
        res %= mod;
    }
    for (int i = 1; i <= k; ++i) {
        res *= inv(i);
        res %= mod;
    }
    return res;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(all(a));
    int t = a[n-k];
    int nn = 0, kk = 0;
    for (int i = n - k; i < n; ++i) {
        if (a[i] == t)
            kk++;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == t)
            nn++;
    }
    cout << cnk(nn, kk) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}