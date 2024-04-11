#include<cstdio>
#include<cstring>
#include<algorithm>

#define mN 610

using namespace std;

struct lhy{
	int x,y,next;
}edge[100010];

int h,l,n,m,p,ans,tot,N,x,y;
int f[mN][mN],sum[mN],son[mN],q[mN],st[mN],ed[mN],out[mN],in[mN];

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void prepare()
{
	for(int i=1;i<=n;i++)
		if(!in[i])q[++l]=i;
	while(h<l)
	{
		int v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!(--in[edge[i].y]))q[++l]=edge[i].y;
	}
}

void doit(int x)
{
	memset(sum,0,sizeof(sum));
	sum[x]=1;
	for(int v=1;v<=n;v++)
		for(int i=son[q[v]];i;i=edge[i].next)
		{
			sum[edge[i].y]+=sum[q[v]];
			if(sum[edge[i].y]>=p)sum[edge[i].y]-=p;
		}
	for(int i=1;i<=n;i++)
		if(ed[i])f[st[x]][ed[i]]=sum[i];
}

int Power(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%p;
		x=1ll*x*x%p;
		m>>=1;
	}
	return nowans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		out[x]++;
		in[y]++;
	}
	int tot1=0,tot2=0;
	for(int i=1;i<=n;i++)
	{
		if(!in[i])st[i]=++tot1;
		if(!out[i])ed[i]=++tot2;
	}
	prepare();
	for(int i=1;i<=n;i++)
		if(st[i])doit(i);
	N=tot1;
	int kind=0;
	for(int i=1;i<=N;i++)
	{
		int now=i;
		for(int j=i+1;j<=N;j++)
			if(abs(f[j][i])>abs(f[now][i]))now=j;
		if(now^i)
		{
			kind^=1;
			for(int j=1;j<=N;j++)
				swap(f[i][j],f[now][j]);
		}
		for(int j=i+1;j<=N;j++)
		{
			int nowval=1ll*f[j][i]*Power(f[i][i],p-2)%p;
			for(int k=i;k<=N;k++)
			{
				f[j][k]-=1ll*nowval*f[i][k]%p;
				if(f[j][k]<0)f[j][k]+=p;
			}
		}
	}
	ans=1;
	for(int i=1;i<=N;i++)
		ans=1ll*ans*f[i][i]%p;
	if(kind)ans=-ans;
	if(ans<0)ans+=p;
	printf("%d\n",ans);
}