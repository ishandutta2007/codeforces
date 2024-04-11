#include<bits/stdc++.h>
using namespace std;
int n, Mx, dp1[105][55][2], dp2[105][55][2];
string s;
int main()
{
    cin >> s >> n;
    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp1[i][j][0] = dp2[i][j][1] = -1e9;
            dp2[i][j][0] = dp1[i][j][1] = 1e9;
        }
    }
    for (int j = 0; j <= n; j++)
    {
        if ((s[0] == 'F' && j % 2 == 0) || (s[0] == 'T' && j % 2 == 1))
        {
            dp1[0][j][0] = dp1[0][j][1] = 1;
        }
        else
        {
            dp2[0][j][0] = dp2[0][j][1] = 0;
        }
    }
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (s[i] == 'F')
            {
                if (abs(dp1[i - 1][j][0]) != 1e9)
                {
                    dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][0] + 1);
                }
                if (abs(dp1[i - 1][j][1]) != 1e9)
                {
                    dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][1] + 1);
                }
                if (j > 0)
                {
                    if (abs(dp2[i - 1][j - 1][0]) != 1e9)
                    {
                        dp1[i][j][0] = max(dp1[i][j][0], dp2[i - 1][j - 1][0]);
                    }
                    if (abs(dp2[i - 1][j - 1][1]) != 1e9)
                    {
                        dp1[i][j][0] = max(dp1[i][j][0], dp2[i - 1][j - 1][1]);
                    }
                }
                if (abs(dp1[i - 1][j][0]) != 1e9)
                {
                    dp1[i][j][1] = min(dp1[i][j][1], dp1[i - 1][j][0] + 1);
                }
                if (abs(dp1[i - 1][j][1]) != 1e9)
                {
                    dp1[i][j][1] = min(dp1[i][j][1], dp1[i - 1][j][1] + 1);
                }
                if (j > 0)
                {
                    if (abs(dp2[i - 1][j - 1][0]) != 1e9)
                    {
                        dp1[i][j][1] = min(dp1[i][j][1], dp2[i - 1][j - 1][0]);
                    }
                    if (abs(dp2[i - 1][j - 1][1]) != 1e9)
                    {
                        dp1[i][j][1] = min(dp1[i][j][1], dp2[i - 1][j - 1][1]);
                    }
                }

                if (abs(dp2[i - 1][j][0]) != 1e9)
                {
                    dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][0] - 1);
                }
                if (abs(dp2[i - 1][j][1]) != 1e9)
                {
                    dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][1] - 1);
                }
                if (j > 0)
                {
                    if (abs(dp1[i - 1][j - 1][0]) != 1e9)
                    {
                        dp2[i][j][0] = min(dp2[i][j][0], dp1[i - 1][j - 1][0]);
                    }
                    if (abs(dp1[i - 1][j - 1][1]) != 1e9)
                    {
                        dp2[i][j][0] = min(dp2[i][j][0], dp1[i - 1][j - 1][1]);
                    }
                }

                if (abs(dp2[i - 1][j][0]) != 1e9)
                {
                    dp2[i][j][1] = max(dp2[i][j][1], dp2[i - 1][j][0] - 1);
                }
                if (abs(dp2[i - 1][j][1]) != 1e9)
                {
                    dp2[i][j][1] = max(dp2[i][j][1], dp2[i - 1][j][1] - 1);
                }
                if (j > 0)
                {
                    if (abs(dp1[i - 1][j - 1][0]) != 1e9)
                    {
                        dp2[i][j][1] = max(dp2[i][j][1], dp1[i - 1][j - 1][0]);
                    }
                    if (abs(dp1[i - 1][j - 1][1]) != 1e9)
                    {
                        dp2[i][j][1] = max(dp2[i][j][1], dp1[i - 1][j - 1][1]);
                    }
                }
            }
            if (s[i] == 'T')
            {
                if (j > 0)
                {
                    if (abs(dp1[i - 1][j - 1][0]) != 1e9 && j > 0)
                    {
                        dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][0] + 1);
                    }
                    if (abs(dp1[i - 1][j - 1][1]) != 1e9 && j > 0)
                    {
                        dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][1] + 1);
                    }
                }
                if (abs(dp2[i - 1][j][0]) != 1e9)
                {
                    dp1[i][j][0] = max(dp1[i][j][0], dp2[i - 1][j][0]);
                }
                if (abs(dp2[i - 1][j][1]) != 1e9)
                {
                    dp1[i][j][0] = max(dp1[i][j][0], dp2[i - 1][j][1]);
                }

                if (j > 0)
                {
                    if (abs(dp1[i - 1][j - 1][0]) != 1e9 && j > 0)
                    {
                        dp1[i][j][1] = min(dp1[i][j][1], dp1[i - 1][j - 1][0] + 1);
                    }
                    if (abs(dp1[i - 1][j - 1][1]) != 1e9 && j > 0)
                    {
                        dp1[i][j][1] = min(dp1[i][j][1], dp1[i - 1][j - 1][1] + 1);
                    }
                }
                if (abs(dp2[i - 1][j][0]) != 1e9)
                {
                    dp1[i][j][1] = min(dp1[i][j][1], dp2[i - 1][j][0]);
                }
                if (abs(dp2[i - 1][j][1]) != 1e9)
                {
                    dp1[i][j][1] = min(dp1[i][j][1], dp2[i - 1][j][1]);
                }

                if (j > 0)
                {
                    if (abs(dp2[i - 1][j - 1][0]) != 1e9 && j > 0)
                    {
                        dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][0] - 1);
                    }
                    if (abs(dp2[i - 1][j - 1][1]) != 1e9 && j > 0)
                    {
                        dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][1] - 1);
                    }
                }
                if (abs(dp1[i - 1][j][0]) != 1e9)
                {
                    dp2[i][j][0] = min(dp2[i][j][0], dp1[i - 1][j][0]);
                }
                if (abs(dp1[i - 1][j][1]) != 1e9)
                {
                    dp2[i][j][0] = min(dp2[i][j][0], dp1[i - 1][j][1]);
                }

                if (j > 0)
                {
                    if (abs(dp2[i - 1][j - 1][0]) != 1e9 && j > 0)
                    {
                        dp2[i][j][1] = max(dp2[i][j][1], dp2[i - 1][j - 1][0] - 1);
                    }
                    if (abs(dp2[i - 1][j - 1][1]) != 1e9 && j > 0)
                    {
                        dp2[i][j][1] = max(dp2[i][j][1], dp2[i - 1][j - 1][1] - 1);
                    }
                }
                if (abs(dp1[i - 1][j][0]) != 1e9)
                {
                    dp2[i][j][1] = max(dp2[i][j][1], dp1[i - 1][j][0]);
                }
                if (abs(dp1[i - 1][j][1]) != 1e9)
                {
                    dp2[i][j][1] = max(dp2[i][j][1], dp1[i - 1][j][1]);
                }
            }
            /*cout << i << " " << j << endl;
            cout << dp1[i][j][0] << " " << dp1[i][j][1] << endl;
            cout << dp2[i][j][0] << " " << dp2[i][j][1] << endl;
            cout << endl;*/
        }
    }
    if (abs(dp1[s.size() - 1][n][0]) != 1e9)
    {
        Mx = max(Mx, abs(dp1[s.size() - 1][n][0]));
    }
    if (abs(dp1[s.size() - 1][n][1]) != 1e9)
    {
        Mx = max(Mx, abs(dp1[s.size() - 1][n][1]));
    }
    if (abs(dp2[s.size() - 1][n][0]) != 1e9)
    {
        Mx = max(Mx, abs(dp2[s.size() - 1][n][0]));
    }
    if (abs(dp2[s.size() - 1][n][1]) != 1e9)
    {
        Mx = max(Mx, abs(dp2[s.size() - 1][n][1]));
    }
    cout << Mx;
    return (0);
}