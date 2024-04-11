#include<bits/stdc++.h>
using namespace std;
const int NX = 1e9 + 7;
int c, dp[5010][5010];
string s, t;
int main()
{
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1) % NX;
            }
        }
        c = (c + dp[i][t.size()]) % NX;
    }
    cout << c % NX;
    return (0);
}