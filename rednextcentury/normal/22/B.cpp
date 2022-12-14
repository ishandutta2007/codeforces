# include <iostream>
# include <algorithm>
using namespace std;
char a[100][100];
int dp[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
           if (a[i][j]=='0')
           {
               while(j-dp[i][j]>=0 && a[i][j-dp[i][j]]=='0')
                    dp[i][j]++;
           }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
           if (a[i][j]=='0')
           {
               int mn=dp[i][j];
               int s=1;
               int x=i;
               while(x>=0)
               {
                   mn=min(mn,dp[x][j]);
                   if (mn==0)
                    break;
                   ans=max(ans,mn*2 + s*2);
                   x--;
                   s++;
               }
           }
        }
    }
    cout<<ans<<endl;
}