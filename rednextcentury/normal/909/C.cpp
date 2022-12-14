#include<bits/stdc++.h>
using namespace std;
long long dp[5001][5004];
long long add[5003];
char a[5001];
long long MOD = 1000000007;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[1][1]=1;
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        long long cur=0;
        for (int j=1;j<=n;j++)
        {
            cur+=add[j];
            cur%=MOD;
            add[j]=0;
            dp[i][j]+=cur;
            dp[i][j]%=MOD;
        }
        for (int j=1;j<=n;j++)
        {
            if (i==n)
                ret=(ret+dp[i][j])%MOD;
            else
            {
                if (a[i]=='f')
                {
                    dp[i+1][j+1]+=dp[i][j];
                    dp[i+1][j+1]%=MOD;
                }
                else
                {
                    add[1]+=dp[i][j];
                    add[1]%=MOD;
                    add[j+1]-=dp[i][j];
                    add[j+1]+=MOD;
                    add[j+1]%=MOD;
                }
            }
        }
    }
    cout<<ret<<endl;
}