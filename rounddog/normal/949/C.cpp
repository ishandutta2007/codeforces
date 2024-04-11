#include<cmath>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 200020

int to[maxn],nxt[maxn],h[maxn],low[maxn],dfn[maxn],n,m,p,colorcnt,instack[maxn],color[maxn];
bool visit[maxn];
int sz[maxn],dd[maxn],ans[maxn],k,o,a[maxn];

using namespace std;

vector <int> s;

void add_edge(int x,int y)
{
    //printf("%d %d\n",x,y);
	p++;
	to[p]=y;
	nxt[p]=h[x];
	h[x]=p;
}

void dfs(int x)
{
	p++;
	instack[x]=1;
	dfn[x]=p;
	low[x]=dfn[x];
	s.push_back(x);
	for (int i=h[x];i;i=nxt[i])
	{
		if (!instack[to[i]]){
			dfs(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if (instack[to[i]]==1) low[x]=min(low[x],dfn[to[i]]);
	}
	if (dfn[x]==low[x]){
		while (s.back()!=x)
		{
		    sz[colorcnt]++;
			color[s.back()]=colorcnt;
			instack[s.back()]=2;
			s.pop_back();
		}
		sz[colorcnt]++;
		color[s.back()]=colorcnt++;
		instack[s.back()]=2;
		s.pop_back();
	}
}


int main()
{
	memset(h,0,sizeof(h));
	memset(nxt,0,sizeof(nxt));
	memset(instack,0,sizeof(instack));
	memset(dd,0,sizeof(dd));
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        if (a[u]==(a[v]+1)%k) add_edge(v,u);
        if (a[v]==(a[u]+1)%k) add_edge(u,v);
    }
	colorcnt=1;p=0;
	for (int i=1;i<=n;i++)
	    if (!instack[i]) dfs(i);
    for (int i=1;i<=n;i++)
    {
        for (int j=h[i];j;j=nxt[j])
        {
            if (color[i]!=color[to[j]]) dd[color[i]]=true;
        }
    }
    o=-1;
    for (int i=1;i<colorcnt;i++) if (!dd[i]&&(o==-1||sz[o]>sz[i])) o=i;
    printf("%d\n",sz[o]);
    for (int i=1;i<=n;i++)
        if (color[i]==o) printf("%d ",i);
    printf("\n");
	return 0;
}