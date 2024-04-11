#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

ll contrib(ll factor, ll n)
{
    if (factor > n) return 0;
    return contrib(factor, n/factor) + n/factor;
}

int fpow(int base, ll exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1LL) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1LL;
    }
    return ans;
}

int main()
{
    ll x, n;
    cin >> x >> n;
    vector<int> factors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);
            factors.push_back(x/i);
        }
    }
    sort(factors.begin(), factors.end());
    vector<int> prime_factors;
    for (int i = 0; i < factors.size(); i++) {
        bool found = false;
        if (factors[i] == 1) found = true;
        for (int j = 0; j < i; j++) {
            if (factors[i] % factors[j] == 0 && factors[j] != 1) {
                found = true; break;
            }
        }
        if (!found) prime_factors.push_back(factors[i]);
    }
    int ans = 1;
    for (int i = 0; i < prime_factors.size(); i++) {
        ans = mul(ans, fpow(prime_factors[i] % MOD, contrib(prime_factors[i], n)));
    }
    printf("%d", ans);
    return 0;
}