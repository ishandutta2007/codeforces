#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int x,y,next;
}edge[300030];

int son[100000],q[200000],a[200000],fa[200000];
long long ff[200000],f[200000],b[200000],sum;
int n,tot,x,y,l,h,v,ToT;

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

inline int cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	scanf("%d",&x);
	q[++l]=x;
	b[x]=1;
	while(h<l)
	{
		v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!b[edge[i].y])
			{
				b[edge[i].y]=1;
				fa[edge[i].y]=v;
				q[++l]=edge[i].y;
			}
	}
	for(int i=l;i;i--)
	{
		v=q[i];
		if(!a[v])continue;
		if(i!=1)ff[v]++,a[v]--;
		ToT=0;
		sum=0;
		for(int j=son[v];j;j=edge[j].next)
			if(edge[j].y!=fa[v]&&ff[edge[j].y])
				b[++ToT]=f[edge[j].y],sum+=ff[edge[j].y];
		sort(b+1,b+1+ToT,cmp);
		if(a[v]<=ToT)
			for(int j=1;j<=a[v];j++)
				f[v]+=1ll*(b[j]+2);
		else
		{
			for(int j=1;j<=ToT;j++)
				f[v]+=1ll*(b[j]+2);
			sum-=ToT;
			a[v]-=ToT;
			if(a[v]>=sum)f[v]+=sum*2ll,ff[v]+=a[v]-sum;
			else f[v]+=a[v]*2ll;
		}
	}
	printf("%I64d",f[x]);
}