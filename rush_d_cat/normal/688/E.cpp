#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
int num[600],dp[600][600];
int main()
{
    memset(dp,0,sizeof(dp));
    int m,n;cin>>n>>m;dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        for(int j=m;j>=0;j--)
        {
            for(int k=m;k>=0;k--)
            {
                if(dp[j][k]&&(k+num[i])<=m){
                    dp[j][k+num[i]]=1;
                    //if(i<=2)cout<<i<<" "<<j<<" "<<(k+num[i])<<endl;
                }
                if(dp[j][k]&&(j+num[i])<=m){
                    dp[j+num[i]][k]=1;
                    //if(i<=2)cout<<i<<" "<<(j+num[i])<<" "<<k<<endl;
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<=m;i++) cnt+=dp[i][m-i];
    printf("%d\n",cnt);
    for(int i=0;i<=m;i++)
    {
        if(dp[i][m-i]){
            printf("%d",i);
            if(i==m)printf("\n");
            else printf(" ");
        }
    }
}