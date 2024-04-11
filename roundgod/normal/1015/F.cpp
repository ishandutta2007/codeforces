/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 23:28:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int pre[MAXN];
int dp[MAXN][MAXN][MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    int sz=(int)str.size();
    pre[0]=0;
    for(int i=sz-1;i>=0;i--)
    {
        string ss=str.substr(0,i);
        if(str[i]=='(') ss+=')'; else ss+='(';
        pre[i]=0;
        for(int k=(int)ss.size();k>=1;k--)
        {
            string tt=ss.substr(ss.size()-k,k);
            if(tt==str.substr(0,k)) {pre[i]=k; break;}
        }
        //printf("%d %d\n",i,pre[i]);
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=sz;k++)
            {
                if(dp[i][j][k]==0) continue;
                //printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
                if(k==sz)
                {
                    (dp[i+1][j+1][sz]+=dp[i][j][k])%=MOD;
                    if(j>0) (dp[i+1][j-1][sz]+=dp[i][j][k])%=MOD;
                }
                else
                {
                    if(str[k]=='(')
                    {
                        (dp[i+1][j+1][k+1]+=dp[i][j][k])%=MOD;
                        if(j>0) (dp[i+1][j-1][pre[k]]+=dp[i][j][k])%=MOD;
                    }
                    else
                    {
                        if(j>0) (dp[i+1][j-1][k+1]+=dp[i][j][k])%=MOD;
                        (dp[i+1][j+1][pre[k]]+=dp[i][j][k])%=MOD;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[2*n][0][sz]);
    return 0;
}