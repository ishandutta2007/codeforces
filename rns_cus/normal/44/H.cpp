#include <bits/stdc++.h>
using namespace std;

#define N 55

typedef long long ll;

int n;
ll dp[N][N][2];

char s[N];

ll calc(int c, int pos, int dif = 0) {
    if (pos == n) return dif;
    if (dp[c][pos][dif] >= 0) return dp[c][pos][dif];
    ll &rlt = dp[c][pos][dif]; rlt = 0;
    c += s[pos] - '0';
    int d = c >> 1;
    rlt += calc(d, pos + 1, dif || d != s[pos] - '0');
    if (c & 1) {
        d = c - d;
        rlt += calc(d, pos + 1, dif || d != s[pos] - '0');
    }
    return rlt;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%s", s);
    n = strlen(s);
    ll ans = 0;
    for (int i = 0; i < 10; i ++) ans += calc(i, 1, i != s[0] - '0');
    printf("%I64d\n", ans);

    return 0;
}