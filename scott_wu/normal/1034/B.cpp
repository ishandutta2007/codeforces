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
const int MAXD = 20;

int N, M;
vector <int> xloc, yloc;
bool dp[(1 << MAXD)];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    if (N > M) swap (N, M);

    if (N == 1)
    {
        int B = M % 6;
        cout << M - min (B, 6 - B) << "\n";
        return 0;
    }

    if (N * (ll) M >= 20)
    {
        ll res = N * (ll) M;
        res -= res % 2;
        cout << res << "\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            xloc.push_back(i);
            yloc.push_back(j);
        }
    }

    int K = xloc.size();
    for (int i = 0; i < (1 << MAXD); i++)
        dp[i] = false;
    dp[(1 << K) - 1] = true;
    for (int i = (1 << K) - 1; i >= 0; i--)
    {
        if (!dp[i]) continue;
        for (int j = 0; j < K; j++)
        {
            if (i & (1 << j))
            {
                for (int k = j + 1; k < K; k++)
                {
                    if (i & (1 << k))
                    {
                        if (abs (xloc[j] - xloc[k]) + abs (yloc[j] - yloc[k]) == 3)
                            dp[i - (1 << j) - (1 << k)] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << K); i++)
    {
        if (dp[i])
        {
            int cc = 0;
            for (int j = 0; j < K; j++)
                if (i & (1 << j))
                    cc++;
            ans = max (ans, K - cc);
        }
    }
    cout << ans << "\n";
}