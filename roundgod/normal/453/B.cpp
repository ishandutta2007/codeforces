/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-29 20:05:37
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int prime[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
vector<int> fact[70];
int dp[105][1<<17],pre[105][1<<17];
int main()
{
    for(int i=0;i<17;i++)
        for(int j=prime[i];j<=60;j+=prime[i])
            fact[j].push_back(i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++) for(int j=0;j<(1<<17);j++) dp[i][j]=INF;
    memset(pre,-1,sizeof(pre));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=60;j++)
        {
            int comb=0;
            for(int k=0;k<(int)fact[j].size();k++) comb+=(1<<fact[j][k]);
            int sup=(1<<17)-1-comb;
            int sub=sup;
            do
            {
                if(dp[i-1][sub]+max(a[i]-j,j-a[i])<dp[i][comb|sub])
                {
                    dp[i][comb|sub]=dp[i-1][sub]+max(a[i]-j,j-a[i]);
                    pre[i][comb|sub]=j;
                }
                sub=(sub-1)&sup;
            }while(sub!=sup);
        }
    }
    int ans=INF,sup=-1;
    for(int i=0;i<(1<<17);i++) 
    {
        if(dp[n][i]<ans)
        {
            ans=dp[n][i];
            sup=i;
        }
    }
    for(int i=n;i>=1;i--)
    {
        b[i]=pre[i][sup];
        int comb=0;
        for(int j=0;j<(int)fact[b[i]].size();j++) comb+=(1<<fact[b[i]][j]);
        comb=(1<<17)-1-comb;
        sup&=comb;
    }
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}