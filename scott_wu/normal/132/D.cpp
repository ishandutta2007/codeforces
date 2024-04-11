#include <iostream>
#include <string>

using namespace std;
const int MAXL = 1000100;

int n;
bool one[MAXL][2];
int next[MAXL][2];
int dp[MAXL][2];
bool last[MAXL][2];

int main()
{
    string str;
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; i++)
    {
        one[i][0] = (str[n-1-i] == '1');
        one[i][1] = !one[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        if (one[i][0])
        {
            for (int j = i; j >= 0; j--)
                one[j][1] = one[j][0];
            break;
        }
    }
    //one[n][0] = 0; one[
    /*for (int i = 0; i < n; i++)
        cout << one[i][0] << " " << one[i][1] << "\n";
    cout << "\n";*/
    for (int i = 0; i <= n; i++)
        next[i][0] = next[i][1] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (one[i-1][0])
            next[i][0] = i - 1;
        else
            next[i][0] = next[i-1][0];
        if (one[i-1][1])
            next[i][1] = i - 1;
        else
            next[i][1] = next[i-1][1];
    }
    /*for (int i = 0; i < n; i++)
        cout << next[i][0] << " " << next[i][1] << "\n";*/
    dp[0][0] = one[0][0] ? 1 : 0;
    dp[0][1] = one[0][1] ? 1 : 0;
    //cout << "\n";
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            last[i][j] = true;
    for (int i = 1; i < n; i++)
    {
        //if (i == 1) cout << one[i][0] << one[i][1] << next[i][0] << next[i][1] << "\n";
        if (one[i][0])
        {
            if (next[i][0] == -1)
            {
                dp[i][0] = 1;
                last[i][0] = true;
            }
            else
            {
                int c1 = 1 + dp[next[i][0]][0];
                int c2 = 1 + dp[next[i][1]][1];
                if (c1 <= c2)
                {
                    dp[i][0] = c1;
                    last[i][0] = true;
                }
                else
                {
                    dp[i][0] = c2;
                    last[i][0] = false;
                }
            }
        }
        if (one[i][1])
        {
            if (next[i][1] == -1)
            {
                dp[i][1] = 1;
                last[i][1] = true;
            }
            else
            {
                int c1 = 1 + dp[next[i][1]][1];
                int c2 = 1 + dp[next[i][0]][0];
                if (c1 <= c2)
                {
                    dp[i][1] = c1;
                    last[i][1] = true;
                }
                else
                {
                    dp[i][1] = c2;
                    last[i][1] = false;
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    cout << dp[n-1][0] << "\n";
    int cur = n-1, cur2 = 0;
    for (int i = 0; i < dp[n-1][0]; i++)
    {
        //cout << cur << " " << cur2 << "\n";
        bool b = last[cur][cur2];
        int pow = cur;
        if (!b) pow++;
        if (cur2 == 0) cout << "+";
        else cout << "-";
        cout << "2^";
        cout << pow << "\n";
        if (!b)
            cur2 = 1 - cur2;
        cur = next[cur][cur2];
    }
    //system ("Pause");
    return 0;
}