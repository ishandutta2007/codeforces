#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN = 210;

struct tour
{
    double prob;
    int nprize;
};

inline bool cmp (tour left, tour right)
{
    return left.nprize > right.nprize;
}

int n, l, K;
tour contest[MAXN];
double dp[MAXN][MAXN][MAXN]; // [loc][nwin][bag]

int main()
{
    cin >> n >> l >> K;
    for (int i = 0; i < n; i++)
    {
        cin >> contest[i].prob;
        contest[i].prob /= 100.0;
    }
    for (int i = 0; i < n; i++)
        cin >> contest[i].nprize;
    sort (contest, contest + n, cmp);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dp[i][j][k] = 0.0;
    dp[0][0][min (n, K)] = 1.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                dp[i+1][j][k] += (1 - contest[i].prob) * dp[i][j][k];
                if (k + contest[i].nprize < 0)
                    continue;
                dp[i+1][j+1][min (n, k + contest[i].nprize)] += contest[i].prob * dp[i][j][k];
            }
        }
    }
    double ans = 0.0;
    for (int i = l; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ans += dp[n][i][j];
    cout << fixed << setprecision (7);
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}