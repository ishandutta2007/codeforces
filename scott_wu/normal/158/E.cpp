#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 4100;

int dp[MAXN][MAXN];
pair <int, int> call[MAXN];
int n, k;

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 86410;
    dp[0][0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> call[i].first >> call[i].second;
    sort (call, call + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= min (i, k); j++)
        {
            ans = max (ans, call[i].first - dp[i][j]);
            dp[i+1][j+1] = min (dp[i+1][j+1], dp[i][j]);
            dp[i+1][j] = min (dp[i+1][j], max (dp[i][j], call[i].first) + call[i].second);
        }
    }
    for (int i = 0; i <= k; i++)
        ans = max (ans, 86401 - dp[n][i]);
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}