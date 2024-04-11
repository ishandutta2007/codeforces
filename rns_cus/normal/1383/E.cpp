#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int dp[N];
char s[N];
const int mod = 1e9 + 7;

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), rlt = 1;
    bool fg = 0;
    for (int i = 1; i <= n; i ++) if (s[i] == '1') fg = 1;
    if (!fg) {
        printf("%d\n", n);
        return 0;
    }
    int st, ed;
    for (st = 1; s[st] == '0'; st ++);
    rlt = 1ll * rlt * st % mod;
    for (ed = n; s[ed] == '0'; ed --);
    rlt = 1ll * rlt * (n + 1 - ed) % mod;

    int ans = 0;
    for (int i = st, j; i < ed; i = j) {
        for (j = i + 1; s[j] == '0'; j ++);
        int cnt = j - i - 1;
        int nxt = ans;
        for (int i = 0; i <= cnt; i ++) {
            nxt = (nxt + ans + 1ll + mod - dp[i]) % mod;
            dp[i] = (ans + 1) % mod;
        }
        ans = nxt;
    }
    ans = 1ll * (ans + 1) * rlt % mod;
    printf("%d\n", ans);

    return 0;
}