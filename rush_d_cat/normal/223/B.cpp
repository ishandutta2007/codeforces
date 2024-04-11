#include <iostream>
#include <cstring>
using namespace std;
#define N (200000+10)
char s1[N], s2[N];
int dp[N], suf[N], pre[27][N];

int main()
{
    scanf("%s %s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1);
    int m = strlen(s2 + 1);

    for (int i = 1; i <= m + 2; i ++)
    {
        for (int j = 0; j < 26; j ++)
        {
            pre[j][i] = pre[j][i-1];
            if (s2[i] == 'a' + j) pre[j][i] ++;
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        if (dp[i-1] == m) {
            dp[i] = m;
        } else {
            dp[i] = (s1[i] == s2[ dp[i-1] + 1 ]) ? (dp[i-1] + 1) : dp[i-1];
        }

    }

    for (int i = n; i >= 1; i --)
    {
        if (suf[i+1] == m) {
            suf[i] = m;
        } else {
            suf[i] = (s1[i] == s2[ m - suf[i+1] ]) ? suf[i+1] + 1 : suf[i+1];
        }
        //printf("%d %d\n", i, suf[i]);
    }

    int ok = 1;
    for (int i = 1; i <= n; i ++)
    {
        int p1 = dp[i-1] + 1;
        int p2 = m - suf[i+1];
        //printf("%d %d\n", p1, p2);
        int id = s1[i] - 'a';
        if (p2 == 0) {if (pre[id][p1] <= 0) ok = 0;} 
        else if(pre[id][p1] - pre[id][p2-1] <= 0) ok = 0;
        //else printf("%d\n", i);
    }

    printf("%s\n", ok ? "Yes" : "No");
}