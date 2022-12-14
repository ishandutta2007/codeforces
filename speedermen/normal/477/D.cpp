#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5123, MaxL = 13, MOD = 1000000007;

char s[MaxN];
int len, p2[MaxN];
int ord[MaxN], where[MaxN], lcp[MaxN];
int st[MaxL][MaxN], h[MaxN], dp[MaxN][MaxN];
unsigned long long pf[MaxN];

inline bool isLess(int a, int b, int l) {
    int i = 0;
    while (i + 63 < l) {
        if (pf[a + i] != pf[b + i]) {
            return pf[a + i] < pf[b + i];
        }
        i += 64;
    }
    for (; i < l; ++i) {
        if (s[a + i] != s[b + i]) {
            return s[a + i] < s[b + i];
        }
    }
    return false;
}

inline int getLcp(int a, int b) {
    int d = h[b - a + 1];
    return min(st[d][a], st[d][b - (1 << d) + 1]);
}

inline bool isLessSA(int a, int b, int l) {
    int pa = where[a], pb = where[b];
    if (pa > pb) {
        pa ^= pb ^= pa ^= pb;
    }
    int Lcp = getLcp(pa, pb - 1);
    if (Lcp < l) {
        return s[a + Lcp] < s[b + Lcp];
    }
    return false;
}

bool cmp(int x, int y) {
    if (isLess(x, y, min(len - x + 1, len - y + 1))) {
        return true;
    }
    if (isLess(y, x, min(len - x + 1, len - y + 1))) {
        return false;
    }
    return x > y;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%s", s + 1);
    len = strlen(s + 1);
    int p = 1;
    while (p <= len && s[p] == '0') {
        p += 1;
    }
    if (p > len) {
        printf("1\n1\n");
        exit(0);
    }
    for (int i = 1; i <= len; ++i) {
        pf[i] = 0;
        for (int j = 0; j < 64; ++j) {
            pf[i] = pf[i] * 2ULL + (s[i + j] == '1' ? 1 : 0);
        }
    }
    for (int i = 1; i <= len; ++i) {
        ord[i] = i;
    }
    sort(ord + 1, ord + len + 1, cmp);
    for (int i = 1; i <= len; ++i) {
        where[ord[i]] = i;
    }
    for (int i = 1; i < len; ++i) {
        int x = ord[i], y = ord[i + 1];
        lcp[i] = 0;
        while (x + lcp[i] <= len && y + lcp[i] <= len && s[x + lcp[i]] == s[y + lcp[i]]) {
            lcp[i] += 1;
        }
    }
    for (int i = 2; i <= len; ++i) {
        h[i] = h[i >> 1] + 1;
    }
    for (int i = 1; i < len; ++i) {
        st[0][i] = lcp[i];
    }
    for (int i = 1; i < MaxL; ++i) {
        for (int j = 1; j + (1 << i) - 1 < len; ++j) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    dp[p][p] = 1;
    for (int i = p; i <= len; ++i) {
        if (s[i] == '0') {
            continue;
        }
        for (int j = i; j <= len; ++j) {
            if ((dp[i][j + 1] += dp[i][j]) >= MOD) {
                dp[i][j + 1] -= MOD;
            }
            if (j + 1 <= len && s[j + 1] == '1' && j + j - i + 1 <= len) {
                int k = j + j - i + 1;
                k += isLessSA(j + 1, i, j - i + 1);
                if ((dp[j + 1][k] += dp[i][j]) >= MOD) {
                    dp[j + 1][k] -= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = p; i <= len; ++i) {
        ans = (ans + dp[i][len]) % MOD;
    }
    printf("%d\n", ans);
    for (int i = p; i <= len; ++i) {
        for (int j = i; j <= len; ++j) {
            dp[i][j] = len + 1;
        }
    }
    dp[p][p] = 1;
    for (int i = p; i <= len; ++i) {
        if (s[i] == '0') {
            continue;
        }
        for (int j = i; j <= len; ++j) {
            if (dp[i][j] > len) {
                continue;
            }
            if (dp[i][j + 1] > dp[i][j]) {
                dp[i][j + 1] = dp[i][j];
            }
            if (j + 1 <= len && s[j + 1] == '1' && j + j - i + 1 <= len) {
                int k = j + j - i + 1;
                k += isLessSA(j + 1, i, j - i + 1);
                if (dp[j + 1][k] > dp[i][j] + 1) {
                    dp[j + 1][k] = dp[i][j] + 1;
                }
            }
        }
    }
    ans = MOD;
    p2[0] = 1;
    for (int i = 1; i <= len; ++i) {
        p2[i] = (p2[i - 1] + p2[i - 1]) % MOD;
    }
    int cur = 0;
    for (int suff = len; suff >= p; --suff) {
        cur = (cur + p2[len - suff] * (s[suff] - '0')) % MOD;
        if (s[suff] == '0' || dp[suff][len] > len) {
            continue;
        }
        if (len - suff <= 20) {
            ans = min(ans, (p - 1 + cur + dp[suff][len]) % MOD);
        } else {
            if (ans == MOD) {
                ans = (p - 1 + cur + dp[suff][len]) % MOD;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}