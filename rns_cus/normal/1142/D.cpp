#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n,  dp[N][15];
char s[N];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) s[i] -= '0';
    long long rlt = 0;
    dp[1][s[1]] = 1;
    for (int i = 1; i <= n; i ++) {
        if (s[i+1]) dp[i+1][s[i+1]] = 1;
        for (int j = s[i+1] + 1; j < 11; j ++) {
            int x = 10 + s[i+1];
            for (int k = 1; k < j; k ++) x += k;
            dp[i+1][x%11] += dp[i][j];
        }
        for (int j = 0; j < 11; j ++) rlt += dp[i][j];
    }
    printf("%I64d\n", rlt);
}