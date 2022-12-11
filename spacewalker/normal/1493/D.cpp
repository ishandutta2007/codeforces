#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 200100;

map<int, int> ivp[NMAX];
multiset<int> vpset[NMAX];
int pfac[NMAX];
ll cgcd = 1;
int n;

int getGCDExp(int p) {
//    printf("%d has %lu nonzero gcds\n", p, vpset[p].size());
    return vpset[p].size() < n ? 0 : *vpset[p].begin();
}

void multPrime(int i, int p) {
    int ga = getGCDExp(p);
    if (ivp[p].count(i) > 0) vpset[p].erase(vpset[p].find(ivp[p][i])); 
    vpset[p].insert(++ivp[p][i]);
    int gb = getGCDExp(p);
//    printf("%d gcd exp from %d to %d\n", p, ga, gb);
//    printf("%d's exp now %d\n", i, ivp[p][i]);
    if (gb - ga == 1) {
        cgcd = (cgcd * p) % MOD; 
    }
}

void multNumber(int i, int x) {
    if (x > 1) {
        multPrime(i, pfac[x]);
        multNumber(i, x / pfac[x]);
    }
}

int main() {
    for (int i = 2; i < NMAX; ++i) pfac[i] = i;
    for (int i = 2; i < NMAX; ++i) {
        if (pfac[i] < i) continue;
        for (int j = 2 * i; j < NMAX; j += i) pfac[j] = i;
    }
    int q; scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int v; scanf("%d", &v); multNumber(i, v); 
    }
    for (int i = 0; i < q; ++i) {
        int j, v; scanf("%d %d", &j, &v); multNumber(j-1, v);
        printf("%lld\n", cgcd);
    }
}