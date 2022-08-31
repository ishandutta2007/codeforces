#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N, K, X;
ll arr[MAXN];
ll dp[MAXN][MAXN]; // at i with j pictures

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> K >> X;
    if (K > N) K = N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1e18;
    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = max (0, i - K + 1); k <= i; k++)
                dp[i+1][j] = max (dp[i+1][j], dp[k][j-1] + arr[i]);
        }
    }

    ll ans = -1;
    for (int i = N - K + 1; i <= N; i++)
        ans = max (ans, dp[i][X]);
    cout << ans << "\n";
}