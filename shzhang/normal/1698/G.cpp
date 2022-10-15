#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll __int128

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

pair<ll, ll> poly_divide(ll x, ll y)
{
    ll highbit = 0;
    for (ll i = 0; i < 35; i++) {
        if (y & ((ll)1 << i)) highbit = i;
    }
    ll res = 0;
    for (ll i = 70 - highbit; i >= 0; i--) {
        if (x & ((ll)1 << (i + highbit))) {
            x ^= (y << i);
            res |= ((ll)1 << i);
        }
    }
    return make_pair(res, x);
}

ll poly_mult(ll poly1, ll poly2)
{
    ll res = 0;
    for (ll i = 0; i < 35; i++) {
        if (poly1 & ((ll)1 << i)) res ^= poly2 << i;
    }
    return res;
}

ll poly_mult(ll poly1, ll poly2, ll mod)
{
    return poly_divide(poly_mult(poly1, poly2), mod).second;
}

ll poly_fpow(ll base, ll exponent, ll mod)
{
    base = poly_divide(base, mod).second;
    ll ans = 1;
    ll cur = base;
    while (exponent) {
        if (exponent & (ll)1) ans = poly_mult(ans, cur, mod);
        cur = poly_mult(cur, cur, mod); exponent >>= (ll)1;
    }
    return ans;
}

char inp[100];
char* s;

int n;

ll solve_factor(ll poly, ll facval)
{
    vector<ll> factors;
    for (ll i = 1; i * i <= facval; i++) {
        if (facval % i == 0) {
            factors.push_back(i);
            factors.push_back(facval / i);
        }
    }
    sort(factors.begin(), factors.end());
    for (int i = 0; i < factors.size(); i++) {
        if (poly_fpow(2, factors[i], poly) == 1) return factors[i];
    }
    return 0;
}

ll GCD(ll x, ll y)
{
    if (y == 0) return x;
    return GCD(y, x % y);
}

ll LCM(ll x, ll y)
{
    return (x / GCD(x, y)) * y;
}

int main()
{
    scanf("%s", inp);
    s = inp; ll shift = 1;
    while (*s == '0') shift++, s++;
    if (*s == '\0') {
        printf("-1"); return 0;
    }
    n = strlen(s);
    if (n == 1) {
        printf("%lld %lld\n", (long long)shift, (long long)(shift + 1));
        return 0;
    }
    ll inpoly = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') inpoly |= ((ll)1 << i);
    }
    vector<pair<ll, ll> > factors;
    for (ll i = 2; i < (1 << 18); i++) {
        ll found_factor = 1;
        int factor_pwr = 0;
        while (true) {
            pair<ll, ll> divres = poly_divide(inpoly, i);
            if (!divres.second) {
                inpoly = divres.first;
                //printf("divide %lld -> %lld\n", (long long)i, (long long)inpoly);
                found_factor = poly_mult(found_factor, i);
                factor_pwr++;
            } else {
                break;
            }
        }
        if (factor_pwr) {
            ll highbit = 0;
            for (ll j = 0; j < 35; j++) {
                if (found_factor & ((ll)1 << j)) highbit = j;
            }
            factors.push_back(make_pair(found_factor, ((ll)1 << highbit) -
                ((ll)1 << (highbit - (highbit / factor_pwr)))));
        }
    }
    if (inpoly > 1) {
        ll highbit = 0;
        for (ll i = 0; i < 35; i++) {
            if (inpoly & ((ll)1 << i)) highbit = i;
        }
        factors.push_back(make_pair(inpoly, ((ll)1 << highbit) - 1));
    }
    ll ans = 1;
    for (int i = 0; i < factors.size(); i++) {
        //printf("%lld\n", (long long)factors[i].first);
        ans = LCM(ans, solve_factor(factors[i].first, factors[i].second));
    }
    printf("%lld %lld", (long long)shift, (long long)(ans + shift));
    return 0;
}