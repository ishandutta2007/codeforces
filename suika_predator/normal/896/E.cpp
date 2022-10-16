#include<iostream>
#include<cstdio>
using namespace std;
#define rg register
const int MAXN=200500,B=323;
int bel[MAXN],lazy[B],maxx[B],pa[B][MAXN],a[MAXN];
int find(int bl,int x){return pa[bl][x]>0?pa[bl][x]=find(bl,pa[bl][x]):x;}
inline void onion(int bl,int x,int y)//x-->y
{
	int xx=find(bl,x),yy=find(bl,y);
	if(xx!=yy)
	{
		pa[bl][yy]+=pa[bl][xx];
		pa[bl][xx]=yy;
	}
}
int n,m;
inline void change(int l,int r,int x)
{
	int bl=bel[l];
	for(rg int i=bl*B; i<bl*B+B; i++)a[i]=find(bl,a[i]);
	for(rg int i=l; i<=r; i++)
	{
		if(a[i]-lazy[bl]>x)
		{
			pa[bl][a[i]]++;
			a[i]-=x;
			pa[bl][a[i]]--;
		}
	}
}
inline int query(int l,int r,int x)
{
	int bl=bel[l],ret=0;
	for(rg int i=bl*B; i<bl*B+B; i++)a[i]=find(bl,a[i]);
	for(rg int i=l; i<=r; i++)
	{
		if(a[i]-lazy[bl]==x)
		{
			ret++;
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(rg int i=0; i<n+B; i++)bel[i]=i/B;
	for(rg int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		pa[bel[i]][a[i]]--;
		maxx[bel[i]]=max(maxx[bel[i]],a[i]);
	}
	int t,l,r,x;
	for(rg int q=1; q<=m; q++)
	{
		scanf("%d%d%d%d",&t,&l,&r,&x);
		l--,r--;
		if(t==1)
		{
			if(bel[l]==bel[r])
			{
				change(l,r,x);
			}
			else
			{
				change(l,bel[l]*B+B-1,x);
				change(bel[r]*B,r,x);
			}
			for(rg int bl=bel[l]+1; bl<bel[r]; bl++)
			{
				if(maxx[bl]>=2*x)
				{
					for(rg int i=1; i<=x; i++)
					{
						onion(bl,i+lazy[bl],i+lazy[bl]+x);
					}
					lazy[bl]+=x;
					maxx[bl]-=x;
				}
				else if(maxx[bl]>x)
				{
					for(rg int i=x+1; i<=maxx[bl]; i++)
					{
						onion(bl,i+lazy[bl],i+lazy[bl]-x);
					}
					maxx[bl]=x;
				}
			}
		}
		else
		{
			int ans=0;
			if(bel[l]==bel[r])
			{
				ans+=query(l,r,x);
			}
			else
			{
				ans+=query(l,bel[l]*B+B-1,x);
				ans+=query(bel[r]*B,r,x);
			}
			for(rg int bl=bel[l]+1; bl<bel[r]; bl++)
			{
				if(x<=maxx[bl])ans+=-pa[bl][find(bl,x+lazy[bl])];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}