#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
int a[30], n, sum[30][1002], ok[1002][1002];
char s[1002];
LL dp[1002];
int l[1002], t[1002];
int main()
{
    cin >> n;
    scanf("%s", s+1);
    for(int i=1;i<=26;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=26;j++)
        {
            sum[j][i] = sum[j][i-1];
        }
        int tmp = s[i] - 'a' + 1;
        sum[tmp][i] = sum[tmp][i-1] + 1; 
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int ac = 1;
            for(int k=1;k<=26;k++)
            {
                if((j - i + 1 > a[k]) && (sum[k][j] - sum[k][i-1]) )
                {
                    ac = 0;
                }
            }
            ok[i][j] = ac;
        }
    }
    dp[0] = 1;
    for(int i=0;i<=n;i++)
    {
        t[i] = 10002; l[i] = 0;
    }
    t[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int tmp = i;
        while(ok[tmp][i] && tmp >= 1)
        {
            t[i] = min(t[tmp-1]+1, t[i]);
            l[i] = max(l[i], l[tmp-1]);
            l[i] = max(l[i], i - tmp + 1);
            dp[i] += dp[tmp-1];
            dp[i] %= MOD;
            tmp --;
        }
    }
    cout << dp[n] << endl;
    cout << l[n] << endl;
    cout << t[n] << endl;
}