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
const int DIFF = 100;

int N, K, X;
ll arr[MAXN];
ll dp[MAXN][MAXN]; // at i with j pictures
ll dmax[MAXN][MAXN];

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
            dp[i][j] = dmax[i][j] = -1e18;
    dp[0][0] = 0;
    dmax[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        int start = max (1, X - (N - i) + 1), end = min (X, i + 1);
        for (int j = start; j <= end; j++)
        {
            int cloc = max (0, i - K + 1);
            ll ans = -1e18;
            while (cloc + DIFF <= i)
            {
                ans = max (ans, dmax[cloc][j-1]);
                cloc += DIFF;
            }
            for (int k = cloc; k <= i; k++)
                ans = max (ans, dp[k][j-1]);
            ans += arr[i];

            dp[i+1][j] = ans;
            if (ans > 0)
            {
                for (int k = max (0, i - DIFF + 1); k <= i; k++)
                    dmax[k][j] = max (dmax[k][j], ans);
            }
        }
    }

    ll ans = -1;
    for (int i = N - K + 1; i <= N; i++)
        ans = max (ans, dp[i][X]);
    cout << ans << "\n";
}