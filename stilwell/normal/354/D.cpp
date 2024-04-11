#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,p,i,j,k,ans;
int f[100005],g[100005],tmp,tmpp;

struct node
{
	int x,y;
}t[100005];
inline bool cmp(const node &a,const node &b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&t[i].y,&t[i].x);
		t[i].y=n-t[i].y+1;
	}
	sort(t+1,t+m+1,cmp);
	k=1;
	for(i=1;i<=n;++i)f[i]=1000000000;
	for(i=1;i<=n;++i)
	{
		p=min(1000,n-i+1);tmpp=0;
		for(;k<=m&&t[k].x==i;++k)
		if(t[k].y>p)ans+=3;
		else g[t[k].y]=i,++tmpp;
		tmp=100000000;
		for(j=0;j<=p;++j)
		{
			if(g[j]==i)--tmpp;
			if(f[j]<tmp)tmp=f[j];
			if(tmp+2+j*(j+1)/2<f[j])f[j]=tmp+2+j*(j+1)/2;
			f[j]+=tmpp*3;
		}
		f[0]=min(f[0],f[1]);
		for(j=1;j<p;++j)f[j]=f[j+1];
		f[p]=100000000;
		for(j=p;j>=1;--j)if(f[j]<f[j-1])f[j-1]=f[j];
	}
	printf("%d\n",f[0]+ans);
}