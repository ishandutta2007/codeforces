#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,r,u,tmp,lim,lmin,rmax;
int f[605][1205],g[1205];
int son[1205],next[1205];

struct node
{
	int l,r,w,s,v;
}t[505];
inline bool cmp(const node &a,const node &b)
{
	if(a.l!=b.l)return a.l<b.l;
	return a.r>b.r;
}

int main()
{
	scanf("%d%d",&n,&m);
	lmin=3*n;rmax=-100;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d%d%d",&t[i].l,&t[i].r,&t[i].w,&t[i].s,&t[i].v);
		++t[i].l;++t[i].r;
		if(t[i].l<lmin)lmin=t[i].l;
		if(t[i].r>rmax)rmax=t[i].r;
	}
	sort(t+1,t+n+1,cmp);
	for(i=n;i>=1;--i)
	{
		next[i]=son[t[i].l];
		son[t[i].l]=i;
	}
	for(i=n;i>=1;--i)
	{
		l=t[i].l;r=t[i].r;
		j=m-t[i].w;if(t[i].s<j)j=t[i].s;
		lim=j;
		for(;j>=0;--j)
		{
			for(k=l-1;k<=r;++k)g[k]=0;
			for(k=l;k<=r;++k)
			{
				if(g[k-1]>g[k])g[k]=g[k-1];
				for(u=son[k];u;u=next[u])
				if(u>i)
				{
					tmp=j-t[u].w;if(t[u].s<tmp)tmp=t[u].s;
					if(tmp>=0)
					{
						if(g[k]+f[u][tmp]>g[t[u].r])
						g[t[u].r]=g[k]+f[u][tmp];
					}
				}
			}
			f[i][j]=g[r]+t[i].v;
		}
		for(j=0;j<lim;++j)
		if(f[i][j]>f[i][j+1])
		f[i][j+1]=f[i][j];
	}
	l=lmin;r=rmax;j=m;
	for(k=l-1;k<=r;++k)g[k]=0;
	for(k=l;k<=r;++k)
	{
		if(g[k-1]>g[k])g[k]=g[k-1];
		for(u=son[k];u;u=next[u])
		{
			tmp=j-t[u].w;if(t[u].s<tmp)tmp=t[u].s;
			if(tmp>=0)
			{
				if(g[k]+f[u][tmp]>g[t[u].r])
				g[t[u].r]=g[k]+f[u][tmp];
			}
		}
	}
	printf("%d\n",g[r]);
}