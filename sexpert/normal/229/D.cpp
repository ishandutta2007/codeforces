#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5005;
int h[MAXN], pre[MAXN], dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        pre[i] = pre[i - 1] + h[i];
    }
    for(int i = 0; i < MAXN; i++)
        fill(dp[i], dp[i] + MAXN, 1000000000);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int k = n - 1; k >= 0; k--)
            dp[i][k] = min(dp[i][k], dp[i][k + 1]);
        for(int k = 1; k <= n; k++)
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][k] + h[i + 1]);
        for(int k = (i > 0), p = i + 1; k < n; k++) {
            while(p <= n && dp[i][k] > pre[p] - pre[i])
                p++;
            if(p > n)
                break;
            dp[p][k + 1] = min(dp[p][k + 1], pre[p] - pre[i]);
        }
    }
    int a = 0;
    while(dp[n][a + 1] < 1000000000)
        a++;
    cout << n - a << '\n';
}