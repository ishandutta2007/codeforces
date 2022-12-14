#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[2222][2222];
ll dp[2222][2222];
ll add[2222][2222];
ll ad2[2222][2222];
int num[2222][2222];
int nu2[2222][2222];
int mod = 1000000007;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%s",a[i]+1);
        for (int j=m;j>=1;j--) {
            num[i][j]=num[i][j+1]+(a[i][j]=='.');
        }
    }
    for (int j=1;j<=m;j++) {
        for (int i=n;i>=1;i--)
            nu2[i][j]=nu2[i+1][j]+(a[i][j]=='.');
    }
    add[1][0]=1;
    add[1][num[1][1]+1]=-1;
    for (int i=1;i<=n;i++)
    {
        ll cur = 0;
        for (int j=1;j<=m;j++) {
            add[i][j]+=add[i][j-1];
            add[i][j]%=mod;
            ad2[i][j]+=ad2[i-1][j];
            ad2[i][j]%=mod;
            ll up = ad2[i][j];
            ll left = add[i][j];
            cur=(add[i][j]+ad2[i][j]);
            cur%=mod;
            dp[i][j]=cur;
            add[i][j]+=up;
            add[i][j]%=mod;
            add[i][j+num[i][j+1]+1]=(add[i][j+num[i][j+1]+1]+mod-up)%mod;
            ad2[i][j]+=left,ad2[i][j]%=mod;
            ad2[i+nu2[i+1][j]+1][j]=(ad2[i+nu2[i+1][j]+1][j]+mod-left)%mod;
        }
    }
    printf("%lld\n",dp[n][m]);
}