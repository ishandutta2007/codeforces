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
typedef double ld;
const int MAXN = 105;
const int MAXD = 1100;

int N;
ld C, T;
pair <int, int> prob[MAXN];
ld dp[MAXN][MAXD]; // min time to solve i probs with j score

int figure()
{
    cin >> N >> C >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> prob[i].first >> prob[i].second;
    }

    sort (prob, prob + N);

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXD; j++)
            dp[i][j] = 1e15;
    dp[0][0] = 0;

    ld RATE = 10.0 / 9.0;
    for (int i = 0; i < N; i++)
    {
        int t = prob[i].first, s = prob[i].second;
        for (int j = i; j >= 0; j--)
        {
            for (int k = 0; k < MAXD; k++)
            {
                dp[j+1][k+s] = min (dp[j+1][k+s], dp[j][k] * RATE + t);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < MAXD; j++)
        {
            if (dp[i][j] > 1e14) continue;
            if (T < i * 10) continue;
            dp[i][j] *= RATE;

            ld nt = T - i * 10;
            ld btime = dp[i][j];
            if (C * dp[i][j] > 1)
            {
                // no time
                ld tbest = (sqrt (C * dp[i][j]) - 1) / C;
                btime = min (btime, tbest + dp[i][j] / (C * tbest + 1));
            }
            if (btime < nt)
            {
                ans = max (ans, j);
                //if (j == 9)
                //    cout << C << " " << dp[i][j] << " " << i << "\n";
            }
        }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int ntest; cin >> ntest;
    for (int test = 0; test < ntest; test++)
    {
        int res = figure();
        cout << res << "\n";
    }
}