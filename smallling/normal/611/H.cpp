#include<cstdio>
#include<cstring>
#include<algorithm>

#define mp make_pair
#define fi first
#define se second

using namespace std;

struct lhy{
	int x,y,next,f;
}edge[200020];

pair<int,int>Tree[1010];

int ans,n,Max,tot,st,ed,Etot,all,Tcnt,S,Aans;
int sum[10][10],root[10],val[10],cnt[10],su[1010],sv[1010];
int son[10010],now[10010],back[10010],pre[10010],dis[10010],sumd[10010];
char s1[110],s2[110];

inline void add(int x,int y,int f)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].f=f;edge[tot].next=son[x];son[x]=tot;
	edge[++tot].x=y;edge[tot].y=x;edge[tot].f=0;edge[tot].next=son[y];son[y]=tot;
}

void SAP()
{
	int i=st,j,t,tmp,flow=0x3f3f3f3f,flag,minn;
	while(dis[st]<ed)
	{
		back[i]=flow;
		flag=0;
		t=now[i];
		while(t!=-1)
		{
			j=edge[t].y;
			if(edge[t].f>0&&dis[j]+1==dis[i])
			{
				flag=1;
				now[i]=t;
				pre[j]=t;
				if(edge[t].f<flow)flow=edge[t].f;
				i=j;
				if(i==ed)
				{
					ans+=flow;
					while(i!=st)
					{
						edge[pre[i]].f-=flow;
						edge[pre[i]^1].f+=flow;
						i=edge[pre[i]].x;
					}
					flow=0x3f3f3f3f;
				}
				break;
			}
			t=edge[t].next;
		}
		if(flag)continue;
		minn=ed-1;
		t=son[i];
		while(t!=-1)
		{
			if(edge[t].f>0&&dis[edge[t].y]<minn)minn=dis[edge[t].y],tmp=t;
			t=edge[t].next;
		}
		now[i]=tmp;
		if(!(--sumd[dis[i]]))break;
		sumd[dis[i]=minn+1]++;
		if(i!=st)flow=back[i=edge[pre[i]].x];
	}
}

void print(int x)
{
	if(!x)return;
	print(x/10);
	putchar(x%10+'0');
}

void doit()
{
	st=1,ed=1+Max+Etot+1;
	tot=-1;
	for(int i=1;i<=ed;i++)
		son[i]=-1;
	for(int i=1;i<=Etot;i++)
	{
		add(st,1+Max+i,sum[su[i]][sv[i]]);
		add(1+Max+i,su[i]+1,0x3f3f3f3f);
		add(1+Max+i,sv[i]+1,0x3f3f3f3f);
	}
	for(int i=1;i<=Max;i++)
		add(1+i,ed,cnt[i]);
	ans=0;
	for(int i=1;i<=ed;i++)
		now[i]=son[i],dis[i]=0,sumd[i]=0;
	sumd[0]=ed;
	SAP();
	if(ans!=all)return;
	for(int i=1,now=1;i<=Max;i++,now*=10)
		root[i]=val[i]=now;
	for(int i=1;i<=Tcnt;i++)
		print(root[Tree[i].fi]),putchar(' '),print(root[Tree[i].se]),putchar('\n');
	int u,v;
	for(int i=1;i<=Etot;i++)
	{
		for(int j=son[i+1+Max];j!=-1;j=edge[j].next)
		{
			v=edge[j].y-1;
			if(v<1||v>Max)continue;
			u=su[i]+sv[i]-v;
			for(int k=edge[j^1].f;k;k--)
				print(root[u]),putchar(' '),print(++val[v]),putchar('\n');
		}
	}
	exit(0);
}

void dfs(int can,int now)
{
	if(now==((1<<Max)-1))
	{
		doit();
		return;
	}
	if(!can)return;
	int j,u,v,flag;
	for(j=0;j<Max;j++)
		if(can&(1<<j))break;
	dfs(can^(1<<j),now);
	for(int s=S^now;s;s=(s-1)&(S^now))
	{
		flag=1;
		for(int i=0;i<Max;i++)
			if(s&(1<<i))
			{
				u=i+1,v=j+1;
				if(u>v)swap(u,v);
				sum[u][v]--;
				if(sum[u][v]<0)flag=0;
				Tree[++Tcnt]=mp(u,v);
			}
		if(flag)dfs((can^(1<<j))|s,now|s);
		for(int i=0;i<Max;i++)
			if(s&(1<<i))
			{
				u=i+1,v=j+1;
				if(u>v)swap(u,v);
				sum[u][v]++;
				Tcnt--;
			}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,now=1;now<=n;i++,now*=10)
		cnt[i]=min(now*10,n+1)-now-1,all+=cnt[i],Max=i;
	S=(1<<Max)-1;
	int l1,l2;
	for(int i=1;i<n;i++)
	{
		l1=l2=0;
		char ch=getchar();
		while(ch!='?')ch=getchar();
		while(ch=='?')l1++,ch=getchar();
		while(ch!='?')ch=getchar();
		while(ch=='?')l2++,ch=getchar();
		sum[l1][l2]++;
	}
	for(int i=1;i<=Max;i++)
		for(int j=i;j<=Max;j++)
		{
			if(i!=j)sum[i][j]+=sum[j][i],sum[j][i]=0;
			Etot++;
			su[Etot]=i;
			sv[Etot]=j;
		}
	dfs(1,1);
	puts("-1");
}