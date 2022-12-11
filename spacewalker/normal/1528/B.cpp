#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 1000050;

int divCount[NMAX];
ll ans[NMAX], anspsum[NMAX];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < NMAX; ++i) {
        for (int j = i; j < NMAX; j += i) ++divCount[j];
    }
    ans[1] = 1;
    anspsum[1] = 1;
    for (int i = 2; i < NMAX; ++i) {
        ans[i] = anspsum[i-1] + divCount[i];
        anspsum[i] = ans[i] + anspsum[i-1];
        ans[i] %= MOD;
        anspsum[i] %= MOD;
    }
    printf("%lld\n", ans[n]);
}