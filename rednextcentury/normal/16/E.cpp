#include<bits/stdc++.h>
using namespace std;
int n;
double dp[2000200],a[20][20];
double solve(int u)
{
    if((u)==(1<<n)-1)
        return 1;
    if(dp[u]>-0.5)
    {
        return dp[u];
    }
    double ret=0;
    double numAlive = 1;
    for (int i=0;i<n;i++)
        if ((1<<i)&u)numAlive+=1;
    for(int i=0;i<n;i++)
    {
        if((u&(1<<i))==0)
        {
            for(int j=0;j<n;j++)
                if((u&(1<<j)))
                 ret+=(1/(numAlive*(numAlive-1)/2))*a[j][i]*solve((1<<i)|u);
        }
    }
    return dp[u]=ret;
}
int main()
{
    cin >> n;
    for(int i=0;i<2000000;i++)
        dp[i]=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin >> a[i][j];
    for(int i=0;i<n;i++)
        cout << setprecision(8) << fixed <<  solve(1<<i) << endl;
    return 0;
}