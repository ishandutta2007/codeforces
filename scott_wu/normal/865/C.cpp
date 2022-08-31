#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 55;
const int MAXS = 5500;

int N, R;
int F[MAXN], S[MAXN];
ld P[MAXN];
ld dp[MAXN][MAXS]; // finished i rounds and have score j, expectation of time remaining

ld csolve (ld x)
{
    for (int i = 0; i < MAXS; i++)
    {
        if (i <= R)
            dp[N][i] = 0.;
        else
            dp[N][i] = x;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < MAXS - 200; j++)
        {
            ld d1 = x;
            ld d2 = P[i] * (F[i] + dp[i+1][j + F[i]]) + (1. - P[i]) * (S[i] + dp[i+1][j + S[i]]);

            dp[i][j] = d2;
            if (i)
                dp[i][j] = min (dp[i][j], d1);
        }
    }

    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> R;
    for (int i = 0; i < N; i++)
    {
        cin >> F[i] >> S[i] >> P[i];
        P[i] /= 100.;
    }

    ld lo = 0.0, hi = 1e16;
    while (hi - lo > 1e-11)
    {
        ld mid = (hi + lo) / 2.;
        ld sscore = csolve (mid);
        if (sscore > mid)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << fixed << setprecision(11);
    cout << lo << "\n";
    return 0;
}