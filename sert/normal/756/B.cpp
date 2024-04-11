#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
int dp[N], t[N], tm[N];
int n, x, v, p;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", t + i + 1);
    }

    dp[0] = 0;
    dp[1] = 20;
    printf("20\n");

    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[i] + 20;
        p = max(0, lower_bound(t, t + n + 1, t[i + 1] - 1439) - t - 1);
        dp[i + 1] = min(dp[i + 1], dp[p] + 120);

        p = max(0, lower_bound(t, t + n + 1, t[i + 1] - 89) - t - 1);
        dp[i + 1] = min(dp[i + 1], dp[p] + 50);

        printf("%d\n", dp[i + 1] - dp[i]);
    }

    return 0;
}