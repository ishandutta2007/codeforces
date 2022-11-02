#include <bits/stdc++.h>
using namespace std;

#define N 252

int n, m, hs[N], cnt[N], rad[N<<1], pw[26];
char s[N][N];

const int base = 513;
const int mod = 1e9 + 7;

bool cmp(int i, int j) {
    return cnt[i] == cnt[j] && hs[i] == hs[j];
}

int manacher(int l, int r) {
    int L = 2 * (r - l) - 1, rlt = 0;
    for (int i = 0, j = 0, k; i < L; i += k, j = max(j - k, 0)) {
        while (i - j >= 0 && i + j < L && cmp((i - j >> 1) + l, (i + j + 1 >> 1) + l)) j ++;
        rad[i] = j;
        for (k = 1; k <= rad[i] && k <= i && rad[i - k] != rad[i] - k; k ++)
            rad[i + k] = min(rad[i - k], rad[i] - k);
    }
    for (int i = 0; i < L; i ++) rlt += (rad[i] + (i & 1 ^ 1)) / 2;
    return rlt;
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < 26; i ++) pw[i] = 1ll * pw[i-1] * base % mod;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j ++) s[i][j] -= 'a';
    }

    long long ans = 0;
    for (int i = 0; i < m; i ++) {
        memset(hs, 0, sizeof hs);
        memset(cnt, 0, sizeof cnt);
        for (int j = i; j < m; j ++) {
            for (int k = 0; k < n; k ++) {
                cnt[k] ^= 1 << s[k][j];
                hs[k] = (hs[k] + pw[s[k][j]]) % mod;
            }
            int l = 0, r = 0;
            while (1) {
                while (r < n && __builtin_popcount(cnt[r]) <= 1) r ++;
                ans += manacher(l, r);
                if (r == n) break;
                l = ++ r;
            }
        }
    }
    printf("%I64d\n", ans);
}