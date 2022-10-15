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

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return ans;
}

int fact[1000005];
int ifact[1000005];

int n;
int freq[1000005];

bool comp[1000005];
int mu[1000005];

int cnt[1000005], tot[1000005];

int GCD(int x, int y)
{
    if (y == 0) return x;
    return GCD(y, x % y);
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        freq[i] = 0; cnt[i] = 0; tot[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); freq[x]++;
    }
    vector<int> present;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i]) {
            present.push_back(i);
            g = GCD(g, freq[i]);
        }
    }
    if (present.size() == 1) {
        printf("1\n"); return;
    }
    vector<int> psizes;
    for (int periods = 1; periods <= g; periods++) {
        if (g % periods) continue;
        int psize = n / periods;
        cnt[psize] = fact[psize];
        psizes.push_back(psize);
        for (int idx = 0; idx < present.size(); idx++) {
            int j = present[idx];
            cnt[psize] = mul(cnt[psize], ifact[freq[j] / periods]);
        }
        int sameways = 0;
        if (psize == 1) {
            sameways = 1;
        } else {
            for (int idx = 0; idx < present.size(); idx++) {
                int j = present[idx];
                if (freq[j] / periods >= 2) {
                    sameways += mul(cnt[psize], mul(ifact[psize],
                        mul(fact[psize - 2], mul(fact[freq[j] / periods],
                        ifact[freq[j] / periods - 2]))));
                    if (sameways >= MOD) sameways -= MOD;
                }
            }
        }
        tot[psize] = mul(n, sameways);
        //printf("cnt %d %d, tot %d %d\n", psize, cnt[psize], psize, tot[psize]);
    }
    int numer = 0, denom = 0;
    for (int idx = 0; idx < psizes.size(); idx++) {
        int psize = psizes[idx];
        int inv = fpow(psize, MOD - 2);
        for (int idx2 = 0; idx2 < psizes.size(); idx2++) {
            int psize2 = psizes[idx2];
            if (psize % psize2 == 0) {
                numer += mul(mul(tot[psize2], mu[psize / psize2]), inv);
                denom += mul(mul(cnt[psize2], mu[psize / psize2]), inv);
                if (numer >= MOD) numer -= MOD;
                if (denom >= MOD) denom -= MOD;
            }
        }
    }
    printf("%lld\n", (n + MOD - mul(numer, fpow(denom, MOD - 2))) % MOD);
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fact[i] = mul(i, fact[i-1]);
        mu[i] = 1;
    }
    ifact[1000000] = fpow(fact[1000000], MOD - 2);
    for (int i = 999999; i >= 0; i--) ifact[i] = mul(i + 1, ifact[i+1]);
    for (int i = 2; i <= 1000000; i++) {
        if (comp[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) comp[j] = true;
    }
    for (int i = 2; i <= 1000000; i++) {
        if (comp[i]) continue;
        for (int j = i; j <= 1000000; j += i) {
            if ((j / i) % i == 0) {
                mu[j] = 0;
            } else {
                mu[j] = -mu[j];
            }
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        if (mu[i] < 0) mu[i] += MOD;
    }
    //for (int i = 1; i <= 10; i++) {
    //    printf("%d %d\n", fact[i], mu[i]);
    //}
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}