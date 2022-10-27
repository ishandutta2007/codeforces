#include <iostream>
#include <cstring>
using namespace std;

char s[3010];
int dp[3010], pre[3010];
bool ok[3010][3010], sam[3010][3010], vis[3010];

bool chk(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);

    for (int i = 1; i <= n; i ++)
    {
        for (int j = i; j <= n; j ++)
        {
            if (i == j) 
            {
                sam[i][j] = 1;
                continue;
            } 
            
            sam[i][j] = sam[i][j-1] & ( s[j] == s[j-1] );
        }
    }


    for (int i = 1; i <= n; i ++)
    {

        int cnt = 0;

        for (int j = i; j <= n; j ++)
        {
            if ( ! chk(s[j]) )
            {
                cnt ++;

                if ( cnt >= 3 && ( !sam[j-cnt+1][j] ) )
                {
                    break;
                }

            } else {
                cnt = 0;
            }

            ok[i][j] = 1;
            //printf("(%d,%d)\n", i, j);

        }

    }

    for (int i = 1; i <= n; i ++)
    {
        dp[i] = 100000;
    }
    dp[1] = 0;


    for (int i = 2; i <= n; i ++)
    {
        for (int j = 0; j < i; j ++)  //[j+1, i]
        {
            if ( ok[j+1][i] && dp[j] + 1 < dp[i])
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    }

    int tmp = n;
    while (tmp)
    {
        vis[tmp] = 1;
        tmp = pre[tmp];
    }

    for (int i = 1; i <= n; i ++)
    {
        printf("%c", s[i]);
        if (vis[i]) printf(" ");
    }



}