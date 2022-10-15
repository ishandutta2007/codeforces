/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-30 01:01:44
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x,mask;
bool vis[MAXN],sub[MAXN];
void dfs(int type,int v)
{
    if(type==0)
    {
        vis[v]=false;
        if(!sub[mask-v]) dfs(1,mask-v);
    }
    else
    {
        sub[v]=true;
        if(vis[v]) dfs(0,v);
        for(int i=0;i<n;i++)
        {
            int to=v&(mask-(1<<i));
            if(!sub[to]) dfs(1,to);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    mask=(1<<n)-1;
    memset(vis,false,sizeof(vis));
    memset(sub,false,sizeof(sub));
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        vis[x]=true;
    }
    int cnt=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(vis[i])
        {
            cnt++;
            dfs(0,i);
        }
    }
    printf("%d\n",cnt);
    return 0;
}