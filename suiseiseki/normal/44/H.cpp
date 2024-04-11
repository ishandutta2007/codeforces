#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=100001;
int n,a[55];
ll dp[55][10];
char s[55];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    for(int i=0;i<10;i++)dp[1][i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<10;j++)
        {
            int k=(j+a[i+1])/2,l=(j+a[i+1]+1)/2;
            dp[i+1][k]+=dp[i][j];
            if(k!=l)dp[i+1][l]+=dp[i][j];
        }
    ll ans=0;
    for(int i=0;i<10;i++)ans+=dp[n][i];
    int flag=1;
    for(int i=2;i<=n;i++)
    {
        if((a[i-1]+a[i])/2==a[i]||(a[i-1]+a[i]+1)/2==a[i])continue;
        else    
        {
            flag=0;
            break;
        }
    }
    printf("%I64d\n",ans-flag);
    return 0;
}