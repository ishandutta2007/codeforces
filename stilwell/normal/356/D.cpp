#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>
using namespace std;

int n,s,S,Sn,i,j,k;
int a[100005],son[100005];
bitset<70005> now,f[505],g[505];
bool use[100005];

struct node
{
	int x,id;
}t[70005];
inline bool cmp(const node &a,const node &b){return a.x<b.x;}

int main()
{
	scanf("%d%d",&n,&s);S=300;
	for(i=1;i<=n;++i)scanf("%d",&a[i]),t[i].x=a[i],t[i].id=i;
	sort(t+1,t+n+1,cmp);
	f[0][0]=now[0]=1;
	for(i=1;i<=n;++i)
	{
		now|=now<<t[i].x;
		if(i%S==0&i!=n)f[++Sn]=now;
	}
	if(!now[s])
	{
		printf("-1\n");
		return 0;
	}
	for(i=Sn;i>=0;--i)
	{
		k=i*S;if(k>n)k=n;
		g[0]=now=f[i];
		for(j=1;j<=S;++j)
		if(k+j<=n)
		{
			now|=now<<t[k+j].x;
			g[j]=now;
		}
		for(j=S;j>=1;--j)
		if(k+j<=n&&t[k+j].x<=s&&g[j-1][s-t[k+j].x])
		{
			use[k+j]=true;
			s-=t[k+j].x;
		}
	}
	if(!use[n])
	{
		printf("-1\n");
		return 0;
	}
	for(i=n;i>=1;--i)
	if(!use[i])
	{
		son[t[i+1].id]=t[i].id;
		a[t[i+1].id]-=a[t[i].id];
	}
	for(i=1;i<=n;++i)
	{
		printf("%d",a[i]);
		if(son[i])printf(" 1 %d\n",son[i]);
		else printf(" 0\n");
	}
}