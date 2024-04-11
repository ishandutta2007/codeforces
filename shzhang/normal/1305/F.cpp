#include <cstdio>
#include <set>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

void factor(ll val, set<ll>& factors)
{
    if (val <= 1) return;
    ll orig = val;
    for (ll fac = 2; fac * fac <= orig; fac++) {
        if (val % fac == 0) {
            factors.insert(fac);
            while (val % fac == 0) val /= fac;
        }
    }
    if (val != 1) factors.insert(val);
}

int n;
ll a[200005];

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    ll ans = n;
    for (int itr = 1; itr <= 30; itr++) {
        int idx = (rng() % n) + 1;
        set<ll> factors;
        factor(a[idx] + 1LL, factors);
        factor(a[idx], factors);
        factor(a[idx] - 1LL, factors);
        for (auto it = factors.begin(); it != factors.end(); it++) {
            ll fac = *it;
            ll curans = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] < fac) {
                    curans += fac - a[i];
                } else {
                    curans += min(a[i] % fac, fac - (a[i] % fac));
                }
            }
            //printf("%lld %lld\n", fac, curans);
            ans = min(ans, curans);
        }
    }
    printf("%lld", ans);
    return 0;
}