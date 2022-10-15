#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define ll long long

ll D;

vector<ll> factors;
vector<ll> prime_factors;
map<ll, map<ll, int> > pfcnt;

int factorial[105];
int factinv[105];

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

ll GCD(ll a, ll b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

int route_cnt(ll val)
{
    //fprintf(stderr, "HERE");
    int total_pf = 0;
    for (int i = 0; i < prime_factors.size(); i++) {
        total_pf += pfcnt[prime_factors[i]][val];
    }
    int ans = factorial[total_pf];
    for (int i = 0; i < prime_factors.size(); i++) {
        ans = mul(ans, factinv[pfcnt[prime_factors[i]][val]]);
    }
    //printf("%lld %d %d\n", val, total_pf, ans);
    return ans;
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= 100; i++) factorial[i] = mul(factorial[i-1], i);
    for (int i = 0; i <= 100; i++) factinv[i] = fpow(factorial[i], MOD - 2);
    scanf("%lld", &D);
    ll tmp = D; int q;
    for (ll i = 1; i * i <= D; i++) {
        if (D % i == 0) {
            factors.push_back(i);
            if (i * i != D) factors.push_back(D / i);
            if (i != 1 && tmp % i == 0) {
                prime_factors.push_back(i);
                while (tmp % i == 0) tmp /= i;
            }
        }
    }
    //fprintf(stderr, "HERE");
    if (tmp != 1) prime_factors.push_back(tmp);
    for (int i = 0; i < factors.size(); i++) {
        ll fac = factors[i];
        ll val = factors[i];
        //fprintf(stderr, "factor %lld\n", val);
        for (int j = 0; j < prime_factors.size(); j++) {
            ll pf = prime_factors[j]; int cnt = 0;
            //fprintf(stderr, "pf=%lld\n", pf);
            while (val % pf == 0) val /= pf, cnt++;
            pfcnt[pf][fac] = cnt;
            //printf("pfcnt %lld %lld %d\n", pf, fac, cnt);
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll gc = GCD(a, b);
        printf("%d\n", (int)mul(route_cnt(a / gc), route_cnt(b / gc)));
    }
    return 0;
}