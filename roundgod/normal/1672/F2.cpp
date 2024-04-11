#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
using namespace std;
struct edge{int to,cap,rev,id;};
int t,n,a[MAXN],b[MAXN],cnt[MAXN],color[MAXN];
vector<int> G[MAXN];
bool dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0)
		{
			if(!dfs_visit(to)) return false;
		}
        else if(color[to]==1) return false;
	}
	color[v]=2;
    return true;
}
bool toposort()
{
    for(int i=1;i<=n+1;i++) color[i]=0;
	for(int i=1;i<=n+1;i++)
		if(color[i]==0)
            {if(!dfs_visit(i)) return false;}
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int mx=0,c=0;
        for(int i=1;i<=n+1;i++) G[i].clear();
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++;}
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) if(cnt[i]>c) {mx=i; c=cnt[i];}
        for(int i=1;i<=n;i++)
        {
            int x=a[i],y=(b[i]==mx?n+1:b[i]);
            G[x].push_back(y);
        }
        if(toposort()) puts("AC"); else puts("WA");
    }
    return 0;
}