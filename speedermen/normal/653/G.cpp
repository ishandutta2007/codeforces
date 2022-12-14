#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300005, MaxL = 20, MOD = 1000000007;

int lp[MaxN], pr[MaxN], sz, t[MaxN];
int fact[MaxN], rfact[MaxN], inv[MaxN];
int pos[MaxN][MaxL], what[MaxN], pref[MaxN];

int getComb(int n, int k) {
    return n < k ? 0 : 1LL * fact[n] * rfact[n - k] % MOD * rfact[k] % MOD;
}

int Calc(int val[]) {
    int h = 0;
    for (int i = MaxL - 1; i >= 0; --i) {
        if (val[i] != 0) {
            h = i;
            break;
        }
    }
    int s = val[0], res = 0;
    for (int i = 1; i <= h; ++i) {
        for (int d = 1; d <= val[i]; ++d) {
            what[s + d] = i;
        }
        res += i * val[i];
        s += val[i];
    }
    res = 1LL * res * pref[val[0]] % MOD;
    for (int i = val[0] + 1; i <= s; ++i) {
        {
            int sum = 0;
            for (int j = what[i] + 1; j <= h; ++j) {
                sum += val[j] * (j - what[i]);
            }
            res = (res + 1LL * sum * getComb(s - 1, i - 1)) % MOD;
        }
        {
            int sum = 0;
            for (int j = 0; j < what[i]; ++j) {
                sum += val[j] * (what[i] - j);
            }
            res = (res + 1LL * sum * (getComb(s, i) - getComb(s - 1, i - 1) + MOD)) % MOD;
        }
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
    for (int i = 2; i < MaxN; ++i) {
        if (!lp[i]) {
            lp[i] = pr[sz++] = i;
        }
        for (int j = 0; j < sz && i * pr[j] < MaxN && pr[j] <= lp[i]; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < MaxN; ++i) {
        inv[i] = i == 1 ? 1 : 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fact[i] = 1LL * i * fact[i - 1] % MOD;
        rfact[i] = 1LL * inv[i] * rfact[i - 1] % MOD;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        for (int x = t[i]; x > 1; ) {
            int e = lp[x], c = 0;
            while (x % e == 0) {
                c += 1;
                x /= e;
            }
            pos[e][c] += 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] + getComb(n - 1, i - 1)) % MOD;
    }
    int result = 0;
    for (int d = 1; d < MaxN; ++d) {
        if (lp[d] != d) {
            continue;
        }
        pos[d][0] = n;
        for (int i = 1; i < MaxL; ++i) {
            pos[d][0] -= pos[d][i];
        }
        if (pos[d][0] == n) {
            continue;
        }
        result = (result + Calc(pos[d])) % MOD;
    }
    printf("%d\n", result);
    return 0;
}