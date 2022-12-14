#include<bits/stdc++.h>
using namespace std;
int v[1000000];
long long dp[1000000];
unordered_map<long long ,int> mp[1000000];
int main()
{
    int m;
    scanf("%d",&m);
    long long ret=0;
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        v[i-1]=x;
        dp[i]=1;
        long long h1=0,h2=0;
        int len=0;
        for (int j=i-1;j>=0;j--)
        {
            h1=h1*1337+v[j]+1;
            len++;
            int cur=0;
            dp[j]=0;
            for (int k=1;k<=4;k++)
            {
                if (j+k-1>=m)break;
                cur=cur*2+v[j+k-1];
                if (k==4 && (cur==15 || cur==14 || cur==5 || cur==3))break;
                dp[j]+=dp[j+k];
            }
            dp[j]%=1000000007;
            if (++mp[len][h1]==1)
                ret+=dp[j];
            ret%=1000000007;
        }
        printf("%lld\n",ret);
    }
}
//100990200