/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-21 16:30:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next sifdajfodskf
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char mp[MAXN][MAXN];
int need[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    /*if(n==1)
    {
        if(k==0) printf("%s\n",mp[1]+1);
        else puts("a");
        return 0;
    }*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1) need[i][j]=0; else need[i][j]=INF;
            if(i>1) need[i][j]=min(need[i][j],need[i-1][j]);
            if(j>1) need[i][j]=min(need[i][j],need[i][j-1]);
            if(mp[i][j]!='a') need[i][j]++;
        }
    if(need[n][n]<=k)
    {
        for(int i=0;i<2*n-1;i++) printf("a");
        return 0;
    }
    int cur=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(need[i][j]<=k) cur=max(cur,i+j-1);
    string ans(cur,'a');
    vector<P> v;
    for(int i=1;i<=n;i++)
    {
        int j=cur+1-i;
        if(j<1||j>n) continue;
        if(need[i][j]<=k) v.push_back(P(i,j));
    }
    if(cur==0)
    {
        cur++;
        ans+=mp[1][1];
        v.push_back(P(1,1));
    }
    for(int i=cur+1;i<=2*n-1;i++)
    {
        vector<P> valid;valid.clear();
        for(auto it:v)
        {
            if(it.F<n) valid.push_back(P(it.F+1,it.S));
            if(it.S<n) valid.push_back(P(it.F,it.S+1));
        }
        sort(valid.begin(),valid.end());
        valid.erase(unique(valid.begin(),valid.end()),valid.end());
        char now='z';
        for(auto it:valid) now=min(now,mp[it.F][it.S]);
        ans+=now;
        v.clear();
        for(auto it:valid) if(mp[it.F][it.S]==now) v.push_back(it);
    }
    cout<<ans<<endl;
    return 0;
}