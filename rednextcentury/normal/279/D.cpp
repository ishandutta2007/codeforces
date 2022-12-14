#include<bits/stdc++.h>
using namespace std;
int cnt[(1<<24)];
int mx[(1<<24)];
int dp[(1<<24)];
bool ok[(1<<24)];
int need[25][25];
int a[25];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            need[i][j]=-1;
            for (int x=0;x<n;x++)
                if (a[x]+a[j]==a[i])
                    need[i][j]=x;
        }
    }
    int tot = 1<<n;
    for (int i=1;i<tot;i++)
    {
        cnt[i]=__builtin_popcount(i);
        for (int j=n-1;j>=0;j--)
        {
            if ((1<<j)&i)
            {
                mx[i]=j;
                break;
            }
        }
        int id = mx[i]+1;
        if (id>=n)continue;
        for (int j=0;j<n;j++)
        {
            if (((1<<j)&i)==0)
                continue;
            int x = need[id][j];
            if (((1<<x)&i)==0)
                continue;
            ok[i]=true;
            break;
        }
    }
    for (int i=0;i<tot;i++)
        dp[i]=1000;
    dp[1]=1;
    int ret=10000;
    for (int i=1;i<tot;i++)
    {
        if (mx[i]==n-1)
        {
            ret=min(ret,dp[i]);
            continue;
        }
        int x = mx[i]+1;
        if (!ok[i])continue;
        dp[i+(1<<x)]=min(dp[i+(1<<x)] , max(dp[i],cnt[i+(1<<x)]));
        for (int j=0;j<=mx[i];j++)
        {
            if ((1<<j)&i)
            {
                dp[i+(1<<x)-(1<<j)]=min(dp[i+(1<<x)-(1<<j)] , max(dp[i],cnt[i+(1<<x)-(1<<j)]));
            }
        }
    }
    if (ret>100)
        ret=-1;
    cout<<ret<<endl;
}