#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAXN = 510;
const int INF = 1e8;

string str;
int words, n;
int dp[MAXN][MAXN]; // changes for pos i, j words
int last[MAXN][MAXN];
int nc[MAXN][MAXN]; // num changes for substr [a,b]

int main()
{
    cin >> str >> words;
    n = str.length();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            nc[i][j] = 0;
            for (int k = i; k <= (i + j) / 2; k++)
                if (str[k] != str[i+j-k])
                    nc[i][j]++;
        }
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++) //nc[j][i]
        {
            for (int k = 0; k < words; k++)
            {
                if (dp[j][k] + nc[j][i-1] < dp[i][k+1])
                {
                    /*if (i == 4)
                        cout << j << " " << k << " " << dp[j][k] + nc[j][i-1] << "\n";
                    if (i == 7)
                        cout << j << " " << k << " " << dp[j][k] + nc[j][i-1] << "\n";*/
                    dp[i][k+1] = dp[j][k] + nc[j][i-1];
                    last[i][k+1] = j;
                }
            }
        }
    }
    int best = INF, loc;
    for (int i = 0; i <= words; i++)
        if (dp[n][i] < best)
        {
            best = dp[n][i];
            loc = i;
        }
    cout << best << "\n";
    int cur = n, count = 0;
    vector <char> ans;
    while (cur > 0)
    {
        if (cur != n) ans.push_back ('+');
        int prev = last[cur][loc];
        for (int i = cur - 1; i >= prev; i--)
            ans.push_back ((char) (min ((int) str[i], (int) str[cur+prev-1-i])));
        cur = prev;
        loc--;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << "\n";
    //system ("Pause");
    return 0;
}