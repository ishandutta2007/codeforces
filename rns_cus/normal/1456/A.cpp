#include <bits/stdc++.h>
using namespace std;

#define N 100100

int p, k, n, x, y, dp[N];
char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &p, &k);
        scanf("%s", s + 1);

        scanf("%d %d", &x, &y);

        int ans = 2e9;


        for (int i = n; i >= p; i --) {
            dp[i] = (i + k > n) ? 0 : dp[i+k];
            if (s[i] == '0') dp[i] ++;
            ans = min(ans, dp[i] * x + (i - p) * y);
        }
        printf("%d\n", ans);

    }

    return 0;
}