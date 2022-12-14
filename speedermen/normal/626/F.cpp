#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int MD = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MD) {
        a -= MD;
    }
}

int n, k;
int a[N];
int dp[2][222][1111];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; }
    sort(a + 1, a + n + 1);
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = i % 2, nxt = 1 - cur;
        memset(dp[nxt], 0, sizeof(dp[nxt]));
        for (int act = 0; act <= n; ++act) {
            for (int j = 0; j <= k; ++j)
                if (dp[cur][act][j] != 0) {
                    int nj = j + act * (a[i] - a[i - 1]);
                    if (nj > k) {
                        continue;
                    }
                    add(dp[nxt][act][nj], (long long)act * dp[cur][act][j] % MD);
                    add(dp[nxt][act][nj], dp[cur][act][j]);
                    add(dp[nxt][act + 1][nj], dp[cur][act][j]);
                    if (act >= 1) add(dp[nxt][act - 1][nj], (long long)act * dp[cur][act][j] % MD);
                }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i)
        add(ans, dp[1 - n % 2][0][i]);
    cout << ans << endl;
    return 0;
}