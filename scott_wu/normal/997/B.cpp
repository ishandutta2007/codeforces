#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXD = 5500;

int N;
int nx[3] = {4, 9, 49};
int nt[3] = {40, 45, 49};
int dp[MAXD];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;

    dp[0] = 1;
    for (int i = 1; i < MAXD; i++)
        dp[i] = 0;

    if (N <= 100)
    {

        for (int i = 0; i < N; i++)
        {
            for (int k = MAXD - 1; k >= 0; k--)
            {
                if (!dp[k]) continue;
                for (int l = 0; l < 3; l++)
                {
                    dp[k+nx[l]] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < MAXD; i++)
            if (dp[i])
                cnt++;
        cout << cnt << "\n";
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int k = MAXD - 1; k >= 0; k--)
        {
            if (!dp[k]) continue;
            for (int l = 0; l < 3; l++)
            {
                dp[k+nt[l]] = 1;
            }
        }
    }
    int nc = 0;
    for (int i = 0; i < 2000; i++)
        if (!dp[i])
            nc++;

    ll res = 49 * (ll) N + 1;
    cout << res - nc - 12 << "\n";
}