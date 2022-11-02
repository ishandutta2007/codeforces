#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define H 2333333
using namespace std;

int n,m,i,j,k,u,v,ans,ans_u,ans_x,ans_y,x,y;
int son[300005],Next[1000005],ed[1000005],tot;
int tag[300005];
int a[300005],cnt;
int dis[300005],from[300005],q[300005],l,r;
int hson[H+5],hnext[2000005],htot;
long long hw[2000005];
bool flag,done[300005];

void Hash_ins(int u,int v)
{
	if(u>v)swap(u,v);
	long long w=(long long)u*(n+233)+v;
	hw[++htot]=w;
	hnext[htot]=hson[w%H];
	hson[w%H]=htot;
}

bool find_edge(int u,int v)
{
	if(u>v)swap(u,v);
	long long w=(long long)u*(n+233)+v;
	int now=w%H;
	for(int i=hson[now];i;i=hnext[i])if(hw[i]==w)return true;
	return false;
}

vector<int> V[300005];

void print(int x)
{
	if(x!=1)print(from[x]);
	printf("%d ",x);
}

int main()
{
	//freopen("3.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		Hash_ins(u,v);
		++tot;Next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;Next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	for(i=2;i<=n;++i)dis[i]=10000000;
	for(q[l=r=1]=1;l<=r;++l)
	{
		u=q[l];
		for(i=son[u];i;i=Next[i])
		if(dis[ed[i]]>n)
		{
			dis[ed[i]]=dis[u]+1;
			q[++r]=ed[i];
			from[ed[i]]=u;
		}
	}
	ans=dis[n];ans_u=-1;
	
	for(i=1;i<=n;++i)if(dis[i]<=n)V[dis[i]].push_back(i);
	
	if(V[2].size()>0&&4<ans)
	{
		ans=4;
		ans_u=1;
		ans_x=from[V[2][0]];
		ans_y=V[2][0];
	}
	if(V[1].size()>0&&5<ans)
	{
		for(i=0;i<V[1].size()&&5<ans;++i)
		{
			u=V[1][i];
			if(done[u])continue;
			a[cnt=1]=u;
			for(j=son[u];j;j=Next[j])
			if(ed[j]!=1)
			{
				a[++cnt]=ed[j];
				done[ed[j]]=true;
				tag[ed[j]]=u;
			}
			for(j=1;j<=cnt&&5<ans;++j)
			for(k=j+1;k<=cnt&&5<ans;++k)
			if(!find_edge(a[j],a[k]))
			{
				ans=5;
				ans_u=a[j];
				ans_x=u;
				ans_y=a[k];
			}
			for(j=2;j<=cnt&&5<ans;++j)
			{
				v=a[j];
				for(k=son[v];k&&5<ans;k=Next[k])
				if(ed[k]!=1&&ed[k]!=u&&tag[ed[k]]!=u)
				{
					ans=5;
					ans_u=u;
					ans_x=v;
					ans_y=ed[k];
				}
			}
		}
	}
	
	if(ans>n+100)printf("-1\n");
	else
	{
		printf("%d\n",ans);
		if(ans_u>0)
		{
			print(ans_u);
			printf("%d %d %d %d",ans_x,ans_y,ans_u,n);
		}
		else print(n);
		printf("\n");
	}
}