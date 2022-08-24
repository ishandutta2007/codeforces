#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
const int INF = 1000000000;

int n, m;
bool forward[110];
int dp[110][60][2]; // [cloc][#turntaken][lo/hi]

void set (int i, int j, int k, int val)
{
    if (dp[i][j][k] == INF)
    {
        dp[i][j][k] = val;
        return;
    }
    if (k == 1)
        dp[i][j][k] = max (dp[i][j][k], val);
    else
        dp[i][j][k] = min (dp[i][j][k], val);
}

int main()
{
    string str;
    cin >> str;
    m = str.length();
    cin >> n;
    for (int i = 0; i < m; i++)
        forward[i] = (str[i] == 'F');
    int fcount = 0;
    for (int i = 0; i < m; i++)
        fcount += (forward[i] ? 1 : 0);
    //cout << fcount << " " << m - fcount << "\n";
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 60; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INF;
    dp[m][0][0] = 0;
    dp[m][0][1] = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (forward[i])
                {
                    if (abs (dp[i+1][j][k]) < 1000000)
                    {
                        set (i, j, 1 - k, dp[i+1][j][k]+1);
                        set (i, j, k, dp[i+1][j][k]+1);
                    }
                    if (j > 0 && (abs (dp[i+1][j-1][k]) < 1000000))
                    {
                        set (i, j, 1 - k, -1 * dp[i+1][j - 1][k]);
                        set (i, j, k, -1 * dp[i+1][j - 1][k]);
                    }
                }
                else
                {
                    if (j > 0 && (abs (dp[i+1][j-1][k]) < 1000000))
                    {
                        set (i, j, 1 - k, dp[i+1][j - 1][k]+1);
                        set (i, j, k, dp[i+1][j - 1][k]+1);
                    }
                    if (abs (dp[i+1][j][k]) < 1000000)
                    {
                        set (i, j, 1 - k, -1 * dp[i+1][j][k]);
                        set (i, j, k, -1 * dp[i+1][j][k]);
                    }
                }
            }
        }
    }
    /*for (int i = 0; i <= m; i++)
    {
        cout << i << "\n";
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }*/
    int ans = 0;
    for (int i = (n % 2); i <= n; i+=2)
        for (int j = 0; j < 2; j++)
            if (abs (dp[0][i][j]) < 1000000)
                ans = max (ans, (int) abs (dp[0][i][j]));
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}