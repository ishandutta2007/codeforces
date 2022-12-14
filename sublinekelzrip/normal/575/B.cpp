#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
struct Bian
{
	int s,t,last,y;
}bian[1000010];
int maxbian=0,last[500010];
void addbian(int s,int t,int y)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].y=y;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
const int maxlongint=2147483647;
const int inf=1000000000;
int fa[500010];
int pre[500010][20];
int tree[1000010];
int dfsx[500010][2];
int d[500010],now=0,maxd,n;
bool v[500010];
int go[500010];
int dfs(int i)
{
	now++;
	dfsx[i][0]=now;
	int x;
	for(x=last[i];x;x=bian[x].last)
	{
		if(!v[bian[x].t])
		{
			if(bian[x].y==1)
				go[bian[x].t]=1;
			else
				if(bian[x].y==-1)
					go[bian[x].t]=2;
			v[bian[x].t]=1;
			d[bian[x].t]=d[i]+1;
			maxd=max(maxd,d[bian[x].t]);
			fa[bian[x].t]=i;
			dfs(bian[x].t);
		}
	}
	now++;
	dfsx[i][1]=now;
}
inline int getpre()
{
	maxd=(int)(log(maxd+0.5)/log(2))+1;
	int i,j;
	for(i=1;i<=n;i++)
		pre[i][0]=fa[i];
	for(j=1;j<=maxd;j++)
		for(i=1;i<=n;i++)
			pre[i][j]=pre[pre[i][j-1]][j-1];
}
inline int lca(int i,int j)
{
	if(d[i]<d[j])
		swap(i,j);
	int p;
	for(p=maxd;p>=0;p--)
		if(d[pre[i][p]]>=d[j])
			i=pre[i][p];
	for(p=maxd;p>=0;p--)
		if(pre[i][p]!=pre[j][p])
		{
			i=pre[i][p];
			j=pre[j][p];
		}
	return i==j?i:fa[i];
}
inline int lowbit(int i)
{
	return i&(-i);
}
inline int insert(int i,int j)
{
	for(;i<=2*n;i+=lowbit(i))
		tree[i]=tree[i]+j;
}
int num[500010];
inline int change(int i)
{
	insert(dfsx[i][0],num[i]);
	insert(dfsx[i][1],num[i]);
}
inline bool Getchar()
{
	char c=getchar();
	while(c!='Q'&&c!='C')
		c=getchar();
	return c=='C';
}
long long ans=0;
int mi[1000010],h0[100010],h1[100010];
const int mod=inf+7;
void dfs2(int i)
{
	v[i]=1;
	for(int j=last[i];j;j=bian[j].last)
		if(!v[bian[j].t]) 
		{
			dfs2(bian[j].t);
			//cout<<bian[j].t<<' '<<go[bian[j].t]<<' '<<h0[bian[j].t]<<' '<<h1[bian[j].t]<<endl;
			h0[i]+=h0[bian[j].t];
			h1[i]+=h1[bian[j].t];
			if(go[bian[j].t]==1)
				ans=(ans+mi[h0[bian[j].t]])%mod;
			else
				if(go[bian[j].t]==2)
					ans=(ans+mi[h1[bian[j].t]])%mod;
		}
}
int main()
{
	cin>>n;
	mi[1]=1;
	for(int i=2;i<=1000000;i++)
		mi[i]=mi[i-1]*2%mod;
	for(int i=2;i<=1000000;i++)
		mi[i]=(mi[i-1]+mi[i])%mod;	
	int n1,t1,t2,m,t3;
	for(n1=1;n1<n;n1++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t3==1)
		{
			addbian(t1,t2,1);
			addbian(t2,t1,-1);
		}
		else
		{
			addbian(t1,t2,0);
			addbian(t2,t1,0);
		}
	}
	v[1]=1;
	d[1]=1;
	dfs(1);
	getpre();
	cin>>m;
	int now=1;
	while(m--)
	{
		scanf("%d",&t1);
		int k=lca(now,t1);
	//	cout<<t1<<' '<<k<<' '<<now<<endl;
		h0[now]++;
		h1[t1]++;
		h0[k]--;
		h1[k]--;
		now=t1;
	}
	memset(v,0,sizeof(v));
	dfs2(1);
	cout<<ans;
}