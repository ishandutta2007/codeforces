#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m[2],w,h,i,j,k,l,r,o,now;
int ansx[100005],ansy[100005];

struct node
{
	int g,p,t,id;
}t[100005],q[2][100005];
inline bool cmp(const node &a,const node &b)
{
	if(a.p-a.t!=b.p-b.t)return a.p-a.t<b.p-b.t;
	return a.p<b.p;
}

int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",&t[i].g,&t[i].p,&t[i].t);
		if(t[i].g==1)t[i].g=0;else t[i].g=1;
		t[i].id=i;
	}
	sort(t+1,t+n+1,cmp);
	for(l=1;l<=n;l=r+1)
	{
		for(r=l;r<n&&t[r+1].p-t[r+1].t==t[l].p-t[l].t;++r);
		m[0]=m[1]=0;
		for(i=l;i<=r;++i)
		{
			if(t[i].g==1)k=1;else k=0;
			q[k][++m[k]]=t[i];
		}
		for(k=0;k<=1;++k)
		for(i=1;i<=m[k];++i)
		{
			now=q[k][i].id;
			o=m[k]-i+1;
			if(o<=m[k^1])
			{
				if((k^1)==1)
				{
					ansx[now]=w;
					ansy[now]=q[k^1][o].p;
				}
				else
				{
					ansx[now]=q[k^1][o].p;
					ansy[now]=h;
				}
			}
			else
			{
				if(k==1)
				{
					ansx[now]=w;
					ansy[now]=q[k][i+m[k^1]].p;
				}
				else
				{
					ansx[now]=q[k][i+m[k^1]].p;
					ansy[now]=h;
				}
			}
		}
	}
	for(i=1;i<=n;++i)printf("%d %d\n",ansx[i],ansy[i]);
}