#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXP = 100;

int N, P;
ld prob[MAXP][MAXP];
ld pval[2*MAXP][MAXP];
ld dp[2*MAXP][MAXP]; // score of sub-bracket assuming this prediction

int lch (int x)
{
    return 2 * P - (2 * (2 * P - x));
}

void dfs (int cloc, int clo, int chi, ld cscore)
{
    //cout << cloc << " " << clo << " " << chi << " " << cscore << "\n";

    for (int i = 0; i < P; i++)
        dp[cloc][i] = 0.0;
    if (cloc < P)
    {
        return;
    }

    int lc = lch (cloc), rc = lch (cloc) + 1;
    int cmid = (clo + chi) / 2;
    dfs (lc, clo, cmid, cscore / 2.);
    dfs (rc, cmid + 1, chi, cscore / 2.);

    for (int i = clo; i <= cmid; i++)
    {
        for (int j = cmid + 1; j <= chi; j++)
        {
            dp[cloc][i] = max (dp[cloc][i], dp[lc][i] + dp[rc][j] + cscore * pval[cloc][i]);
            dp[cloc][j] = max (dp[cloc][j], dp[lc][i] + dp[rc][j] + cscore * pval[cloc][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(10);

    cin >> N;
    P = 1;
    for (int i = 0; i < N; i++)
        P = 2 * P;

    for (int i = 0; i < P; i++)
        for (int j = 0; j < P; j++)
        {
            cin >> prob[i][j];
            prob[i][j] /= 100.0;
        }


    int lo = 0, hi = P;
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < P; j++)
            pval[i][j] = 0.0;
        pval[i][i] = 1.0;
    }

    while (lo + 1 < hi)
    {
        for (int i = 0; i < P; i++)
            pval[hi][i] = 0.0;

        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
            {
                ld pp = pval[lo][i] * pval[lo+1][j];
                pval[hi][i] += pp * prob[i][j];
                pval[hi][j] += pp * prob[j][i];
            }
        lo += 2;
        hi++;
    }

    dfs (2 * P - 2, 0, P - 1, P / 2.);

    ld ans = 0.0;
    for (int i = 0; i < P; i++)
        ans = max (ans, dp[2 * P - 2][i]);
    cout << ans << "\n";
}