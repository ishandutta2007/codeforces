#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

#define ll long long

int a[1000005];
ll tmp[1000005];
int n;

ll gans = 9000000000000000000LL;

ll check(ll factor)
{
    ll ans = 0;
    for (int i = 1; i <= n; i++) tmp[i] = a[i];
    for (int i = 1; i < n; i++) {
        //ll modval = (((tmp[i] % factor) + factor) % factor);
        ll modval;
        if (tmp[i] < 0) {
            ll amodval = (-tmp[i]) % factor;
            if (amodval == 0) {
                modval = 0;
            } else {
                modval = factor - amodval;
            }
        } else {
            modval = tmp[i] % factor;
        }
        if (modval * 2LL <= factor) {
            tmp[i+1] += modval;
            ans += modval;
        } else {
            tmp[i+1] -= factor - modval;
            ans += factor - modval;
        }
        if (ans >= gans) return ans;
    }
    //printf("%lld %lld\n", factor, ans);
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ll total = 0;
    for (int i = 1; i <= n; i++) total += (ll)a[i];
    if (total == 1) {
        printf("-1"); return 0;
    }
    vector<ll> prime_factors;
    ll orig_total = total;
    for (ll i = 2; i * i <= orig_total; i++) {
        if (total % i == 0) {
            prime_factors.push_back(i);
            while (total % i == 0) total /= i;
        }
    }
    if (total > 1) prime_factors.push_back(total);
    for (int i = 0; i < prime_factors.size(); i++) {
        gans = min(gans, check(prime_factors[i]));
    }
    printf("%lld", gans);
    return 0;
}