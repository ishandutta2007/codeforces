#include <bits/stdc++.h>

const int max_N = (int) 1e6 + 21;
const int mod = 998244353;

struct exkmp {
    int nxt[max_N], ext[max_N];

    void solve(char *s, int n, char *t, int m) {
        int a;
        nxt[1] = m;
        for (int &x = nxt[2] = 0; x < m - 1 && t[x + 1] == t[x + 2]; ++x);
        a = 2;
        for (int i = 3; i <= m; ++i) {
            int p = a + nxt[a] - 1, q = nxt[i - a + 1];
            if (i + q <= p) {
                nxt[i] = q;
            } else {
                int &j = nxt[i] = std::max(0, p - i + 1);
                while (i + j <= m && t[i + j] == t[j + 1]) ++j;
                a = i;
            }
        }
        for (int &x = ext[1] = 0; x < n && x < m && s[x + 1] == t[x + 1]; ++x);
        a = 1;
        for (int i = 2; i <= n; ++i) {
            int p = a + ext[a] - 1, q = nxt[i - a + 1];
            if (i + q <= p) {
                ext[i] = q;
            } else {
                int &j = ext[i] = std::max(0, p - i + 1);
                while (i + j <= n && j <= m && s[i + j] == t[j + 1]) ++j;
                a = i;
            }
        }
        /*
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < ext[i]; ++j) {
                assert(s[i + j] == t[j + 1]);
            }
            if (i + ext[i] <= n && ext[i] < m) {
                assert(s[i + ext[i]] != t[ext[i] + 1]);
            }
        }
        // */
    }
} L, R;

char a[max_N], l[max_N], r[max_N];

int n, m1, m2, dp[max_N], sum[max_N];

inline int cmp(const char *s, int n, const int *ext, int l, int r) {
    int len = r - l + 1;
    if (len != n) return len < n ? -1 : 1;
    int lcp = ext[l];
    if (l + lcp > r || lcp == n) return 0;
    return a[l + lcp] < s[lcp + 1] ? -1 : 1;
}

int main() {
    scanf("%s%s%s", a + 1, l + 1, r + 1);
    n = strlen(a + 1);
    L.solve(a, n, l, m1 = strlen(l + 1));
    /*
    for (int i = 1; i <= n; ++i) {
        printf("L : ext[%d] = %d\n", i, L.ext[i]);
    }
    // */
    R.solve(a, n, r, m2 = strlen(r + 1));
    /*
    for (int i = 1; i <= n; ++i) {
        printf("R : ext[%d] = %d\n", i, R.ext[i]);
    }
    // */
    dp[0] = 1;
    if (a[1] != '0') sum[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int lx = std::max(0, i - m2);
        if (cmp(r, m2, R.ext, lx + 1, i) == 1) ++lx;
        int rx = std::max(0, i - m1);
        if (cmp(l, m1, L.ext, rx + 1, i) == -1) --rx;
        // printf("[%d] lx = %d, rx = %d\n", i, lx, rx);
        if (lx <= rx) {
            dp[i] = sum[rx];
            if (lx) {
                dp[i] = (dp[i] + mod - sum[lx - 1]) % mod;
            }
            if (lx <= i - 1 && i - 1 <= rx && a[i] == '0') {
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            }
        }
        sum[i] = sum[i - 1];
        if (a[i + 1] != '0') {
            sum[i] = (sum[i] + dp[i]) % mod;
        }
        // printf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}