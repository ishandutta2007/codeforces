/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 11:49:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,a[MAXN]; 
unordered_map<int,int> dp[MAXN];
int main()
{
    scanf("%d%d",&n,&d);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);mx=max(mx,x);
        a[x]++;
    }
    int ans=0;
    dp[d][d]=a[d];
    for(int i=d;i<=mx;i++)
    {
        for(auto it=dp[i].begin();it!=dp[i].end();it++)
        {
            //printf("%d %d %d\n",i,it->F,it->S);
            ans=max(ans,it->S);
            if(it->F+i+1<=30000) dp[i+it->F+1][it->F+1]=max(dp[i+it->F+1][it->F+1],it->S+a[i+it->F+1]);
            if(it->F+i<=30000) dp[i+it->F][it->F]=max(dp[i+it->F][it->F],it->S+a[i+it->F]);
            if(it->F+i-1<=30000&&it->F>1) dp[i+it->F-1][it->F-1]=max(dp[i+it->F-1][it->F-1],it->S+a[i+it->F-1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}