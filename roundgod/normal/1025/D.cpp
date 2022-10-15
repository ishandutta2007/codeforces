/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 22:12:32
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 705
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool valid[MAXN][MAXN];
int dp[MAXN][MAXN][2];
int gcd(int a,int b) {if(b==0) return a; return gcd(b,a%b);}
int solve(int l,int r,int k)
{
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    if(l>r) return true;
    int fa;
    if(k==0) fa=r+1; else fa=l-1;
    if(l==r)
    {
        return dp[l][r][k]=valid[l][fa];
    }
    for(int i=l;i<=r;i++)
    {
        if(!valid[i][fa]) continue;
        if(solve(l,i-1,0)&&solve(i+1,r,1)) return dp[l][r][k]=1;
    }
    return dp[l][r][k]=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(gcd(a[i],a[j])>1) valid[i][j]=1; else valid[i][j]=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(solve(1,i-1,0)&&solve(i+1,n,1))
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}