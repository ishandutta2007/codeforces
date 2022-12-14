# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <map>
using namespace std;
int dp[1000000];
int cur[1000000];
struct edge
{
    int a;
    int b;
    int w;
};
bool operator<(edge a , edge b)
{
    return a.w<b.w;
}
edge a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
        cin>>a[i].a>>a[i].b>>a[i].w;
    sort(a,a+m);
    int last=0;
    int ret=0;
    for (int i=0;i<m;i++)
    {
        if (i==m-1)
        {
            for (int j=last;j<=i;j++)
            {
                dp[a[j].b]=max(dp[a[j].b],cur[a[j].a]+1);
                ret=max(ret,cur[a[j].b]);
            }
            for (int j=last;j<=i;j++)
            {
                cur[a[j].b]=dp[a[j].b];
            }
            last=i+1;
        }
        else if (a[i].w!=a[i+1].w)
        {
            for (int j=last;j<=i;j++)
            {
                dp[a[j].b]=max(dp[a[j].b],cur[a[j].a]+1);ret=max(ret,cur[a[j].b]);
            }
            for (int j=last;j<=i;j++)
            {
                cur[a[j].b]=dp[a[j].b];
            }
            last=i+1;
        }
    }
    for (int i=1;i<=n;i++)
    {
        ret=max(ret,dp[i]);
    }
    cout<<ret<<endl;
}