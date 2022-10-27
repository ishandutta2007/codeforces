#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef __int64 ll;
int dp[1000+10][1000+10];
int a[1000000+10];
int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];a[i]%=m;
    }

    if(n>m)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    bool flag = false;
    memset(dp,0,sizeof(dp));

    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(dp[i-1][((j-a[i])%m+m)%m])
            {
                dp[i][j]=1;
                if(j==0) flag=true;
            }
            if(dp[i-1][j])
            {
                dp[i][j]=1;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}