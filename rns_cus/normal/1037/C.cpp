#include <bits/stdc++.h>
using namespace std;

#define N 1000020

int n, dp[N];
char a[N], b[N];

int main() {
    scanf("%d", &n);
    scanf("%s %s", a + 1, b + 1);
    dp[1] = (a[1] != b[1]);
    for (int i = 2; i <= n; i ++) {
        if (a[i] == b[i]) dp[i] = dp[i-1];
        else if (a[i-1] != b[i-1] && a[i-1] != a[i]) dp[i] = dp[i-2] + 1;
        else dp[i] = dp[i-1] + 1;
    }
    cout << dp[n] << endl;
}