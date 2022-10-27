#include <iostream>
using namespace std;
int n, m;
char s[102][102];
int dp[102][102], a[102][102];
int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (s[i][j] == 'B') a[i][j] = -1;
            if (s[i][j] == 'W') a[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (a[i][j] == a[i][j+1] + a[i+1][j] - a[i+1][j+1])
            {

            } else {
                ans ++;
            }
        } 
    }
    cout << ans << endl;
}