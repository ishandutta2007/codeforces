
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

/*
// Running time O(n).
std::vector<long long> mod_inverses(const long long &n, const long long &m){
    std::vector<long long> v(n + 1, 1);
	for (long long i = 2; i <= n; ++i) v[i] = (((-(m / i) * v[m % i]) % m) + m) % m;
	return v;
}
*/

int main(){
    ll n, m;
    cin >> n >> m;
    //vll invs = mod_inverses(n, m);
    vll facs(n + 1, 1);//, inv_facs(n + 1, 1);
    for (ll i = 2; i <= n; ++i){
        facs[i] = (i * facs[i - 1]) % m;
        //inv_facs[i] = (invs[i] * inv_facs[i]) % m;
    }
    ll total = 0;
    for (ll len = 1; len <= n; ++len){
        total += ((((n - len + 1) * (n - len + 1)) % m) * ((facs[len] * facs[n - len]) % m)) % m;
        total %= m;
    }
    cout << total << endl;
    return 0;
}