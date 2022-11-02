
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll MAXI = 100;
    vvll ncr(MAXI + 1, vll(MAXI + 1));
    for (ll i = 0; i <= MAXI; ++i) ncr[i][0] = ncr[i][i] = 1;
    for (ll i = 2; i <= MAXI; ++i) for (ll j = 1; j < i; ++j) ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    long long t;
    cin >> t;
    while (--t >= 0){
        long long n_;
        cin >> n_;
        ll n = n_;
        vll seed;
        for (ll i = 2; n > 0; ++i){
            seed.push_back(n % i);
            n /= i;
        }
        ll k = seed.size();
        vll occs(k + 1);
        for (ll x : seed) ++occs[x];
        ll total1 = 1, left_over = k;
        for (ll i = k; i >= 0; --i){
            if (i == 0) total1 *= ncr[left_over][occs[i]];
            else total1 *= ncr[left_over - i + 1][occs[i]];
            left_over -= occs[i];
        }
        ll total2 = 0;
        if (occs[0] > 0){
            --occs[0];
            left_over = k - 1;
            total2 = 1;
            for (ll i = k; i >= 0; --i){
                if (i == 0) total2 *= ncr[left_over][occs[i]];
                else if (left_over - i + 1 < occs[i]) total2 = 0;
                else total2 *= ncr[left_over - i + 1][occs[i]];
                left_over -= occs[i];
            }
        }
        cout << ((long long) (total1 - total2 - 1)) << endl;
    }
    return 0;
}