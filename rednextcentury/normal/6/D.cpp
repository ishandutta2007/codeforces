# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <vector>
using namespace std;
int h[11];
int dp[11][20][20];
int ba[11][20][20][3];
int af[100000];
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<n;i++)
        cin>>h[i],h[i]++;
    int ans=0;
    while(h[0]>0)
        af[ans]=1,ans++,h[0]-=b,h[1]-=a,h[2]-=b;
    while(h[n-1]>0)
        af[ans]=n-2,ans++,h[n-1]-=b,h[n-2]-=a,h[n-3]-=b;
    for (int i=0;i<n;i++)
        for (int j=0;j<20;j++)
            for (int x=0;x<20;x++)
                dp[i][j][x]=100000000;
    for (int i=0;i<20;i++)
        dp[0][0][i]=0;
    for (int i=1;i<n-1;i++)
    {
        for (int j=0;j<20;j++)
        {
            for (int x=0;x<20;x++)
            {
                for (int k=0;k<20;k++)
                {
                    if (h[i]-x<=a*j+b*k)
                        if (dp[i-1][k][min(j*b,19)]+j<dp[i][j][x])
                            dp[i][j][x]=dp[i-1][k][min(j*b,19)]+j,ba[i][j][x][0]=i-1,ba[i][j][x][1]=k,ba[i][j][x][2]=min(19,j*b);
                }
            }
        }
        for (int j=0;j<20;j++)
            for (int x=1;x<20;x++)
                dp[i][j][x]=min(dp[i][j][x],dp[i][j][x-1]);
    }
    int ret=100000000;
    int num=0;
    for (int j=0;j<20;j++)
    {
        if (dp[n-2][j][0]<ret)
            ret=dp[n-2][j][0],num=j;
    }
    int hu=ans+ret-1;
    int hp=0;
    int id=n-2;
    while(hu>=ans)
    {
        for (int i=0;i<num;i++)
            af[hu--]=id;
        int temp1=ba[id][num][hp][0],temp2=ba[id][num][hp][1],temp3=ba[id][num][hp][2];
        id=temp1;
        num=temp2;
        hp=temp3;
    }
    cout<<ans+ret<<endl;
    for (int i=0;i<ans+ret;i++)
        cout<<af[i]+1<<" ";
    cout<<endl;
}