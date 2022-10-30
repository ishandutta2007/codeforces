
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll n, k, MAXI = 100000;

vpll factorize(ll x){
    vpll f;
    for (ll p = 2; p * p <= x; ++p) if (x % p == 0){
        ll a = 0;
        while (x % p == 0){
            ++a;
            x /= p;
        }
        if (a % k != 0) f.push_back({p, a % k});
    }
    if (x > 1) f.push_back({x, 1 % k});
    return f;
}

ll unfactorize(const vpll &f){
    ll x = 1;
    for (const pll &p : f) for (ll a = 0; a < p.second; ++a){
        x *= p.first;
        if (x > MAXI) return MAXI + 1;
    }
    return x;
}

int main(){
    cin >> n >> k;
    vll v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i];
    vll amounts(MAXI + 1);
    for (ll i = 0; i < n; ++i) ++amounts[unfactorize(factorize(v[i]))];
    ll total = 0;
    for (ll x = 1; x <= MAXI; ++x){
        vpll f = factorize(x);
        for (pll &p : f) p.second = k - p.second;
        ll y = unfactorize(f);
        if (y <= MAXI){
            total += amounts[x] * amounts[y];
            if (x == y) total -= amounts[x];
        }
    }
    cout << total / 2 << endl;
    return 0;
}