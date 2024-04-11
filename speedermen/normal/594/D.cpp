#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 20, MOD = 1000000007;

int pr[MaxN], lp[MaxN], last[MaxN], sz, n, q;
int inv[MaxN], a[MaxN], ans[MaxN];
int fenw[MaxN], prod[MaxN];
vector < pair <int, int> > que[MaxN];

inline int Get(int r) {
    int ans = 1;
    while (r >= 0) {
        ans = 1LL * ans * fenw[r] % MOD;
        r &= r + 1, --r;
    }
    return ans;
}

inline void Update(int r, int val) {
    while (r <= n) {
        fenw[r] = 1LL * fenw[r] * val % MOD;
        r |= r + 1;
    }
}

inline int Inv(int x) {
    return x < MaxN ? inv[x] : 1LL * (MOD - MOD / x) * Inv(MOD % x) % MOD;
}

int main() {
//    freopen("input.txt", "r", stdin);
    inv[1] = 1;
    for (int i = 2; i < MaxN; ++i) {
        if (!lp[i]) {
            lp[i] = pr[sz++] = i;
        }
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        for (int j = 0; j < sz && i * pr[j] < MaxN && pr[j] <= lp[i]; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        que[r].push_back(make_pair(l, i));
    }
    for (int i = 0; i < MaxN; ++i) {
        fenw[i] = 1;
    }
    prod[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        prod[i] = 1LL * prod[i - 1] * x % MOD;
        while (x > 1) {
            int e = lp[x];
            if (last[e] > 0) {
                Update(last[e], 1LL * e * inv[e - 1] % MOD);
            }
            Update(last[e] = i, 1LL * inv[e] * (e - 1) % MOD);
            while (x % e == 0) {
                x /= e;
            }
        }
        for (int j = 0; j < (int)que[i].size(); ++j) {
            int l = que[i][j].first, id = que[i][j].second;
            ans[id] = 1LL * prod[i] * Inv(prod[l - 1]) % MOD;
            ans[id] = 1LL * ans[id] * Get(i) % MOD * Inv(Get(l - 1)) % MOD;
        }
    }
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}