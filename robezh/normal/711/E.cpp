#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 105;
const ll mod = (int)1e6 + 3;

ll fp(ll x, ll k, ll md){
    if(k == 0) return 1;
    ll hf = fp(x, k/2, md);
    return k % 2 ? hf * hf % md * x % md: hf * hf % md;
}

ll inv(ll x, ll md) {
    return fp(x, md - 2, md);
}

ll n, k;

int main() {
    cin >> n >> k;
    if(n <= 63 && (1LL << n) < k) return cout << "1 1" << endl, 0;

    ll numer = 1, denom = 1;
    ll st = fp(2, n, mod);
    ll per = 1;
    for(ll x = st; x > st - mod; x--) per = (per * x) % mod;
    numer = (numer * fp(per, k / mod, mod)) % mod;
    for(ll x = st; x > st - k % mod; x--) numer = (numer * x) % mod;
    denom = fp(fp(2, n, mod), k, mod);

    ll cnt2 = n;

    for(ll pw = 2; pw <= k - 1; pw *= 2) cnt2 += (k - 1) / pw;
    cnt2 = (ll)min((ld)cnt2, (ld)n * k);

    ll inv2 = inv(fp(2, cnt2, mod), mod);
    numer = (numer * inv2 % mod);
    denom = (denom * inv2 % mod);
    numer = denom - numer;
    cout << (numer % mod + mod) % mod << " " << (denom % mod + mod) % mod << endl;


}