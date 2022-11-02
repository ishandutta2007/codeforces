#include<bits/stdc++.h>
using namespace std;

#define N 1000010

char s[N], t[N];
int n, dp[N];

int main() {
    scanf("%d%s%s", &n, s + 1, t + 1);
    if(s[1] == t[1]) dp[1] = 0;
    else dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i] = dp[i-1];
        if(s[i] != t[i]) {
            dp[i] ++;
            if(s[i-1] != t[i-1] && s[i] != s[i-1]) dp[i] = min(dp[i], dp[i-2] + 1);
        }
    }
    printf("%d\n", dp[n]);
}