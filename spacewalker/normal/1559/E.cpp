#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

int ceil(int n, int d) {
    return n / d + (n % d != 0 ? 1 : 0);
}

// each v in bounds represents a [0, v] interval
ll countWithoutGCD(vector<int> &bounds, int m) {
    int n = bounds.size();
    vector<vector<ll>> ct(n + 1, vector<ll>(m + 1));
    // we repurpose ct as a partial sum table
    ct[0].assign(m + 1, 1);
    for (int i = 1; i <= n; ++i) {
        int v = bounds[i-1];
        for (int s = 0; s <= m; ++s) {
            // get sum of ct[i-1][s-v] + ... + ct[i-1][s]
            ll backSum = s - v - 1 >= 0 ? ct[i-1][s-v-1] : 0;
            ct[i][s] = (ct[i-1][s] - backSum + MOD) % MOD;
        }
        for (int s = 1; s <= m; ++s) ct[i][s] = (ct[i][s-1] + ct[i][s]) % MOD;
    }
    return ct[n][m];
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &L[i], &R[i]);
    vector<ll> ansReduced(m + 1);
    for (int d = 1; d <= m; ++d) { // solve for when we require all numbers to be divisible by d
        int red_m = m / d;
        vector<int> redl(n), redr(n);
        for (int i = 0; i < n; ++i) {
            redl[i] = ceil(L[i], d);
            redr[i] = R[i] / d;
        }
        bool numbersExist = true;
        vector<int> smallBounds(n);
        for (int i = 0; i < n; ++i) {
            smallBounds[i] = redr[i] - redl[i];
            if (smallBounds[i] < 0) numbersExist = false;
            red_m -= redl[i];
        }
        if (red_m < 0 || !numbersExist) continue;
        ansReduced[d] = countWithoutGCD(smallBounds, red_m);
    }
    for (int i = m; i > 0; --i) {
        for (int j = 2 * i; j < m; j += i) ansReduced[i] = (ansReduced[i] - ansReduced[j] + MOD) % MOD;
    }
    printf("%lld\n", ansReduced[1]);
}