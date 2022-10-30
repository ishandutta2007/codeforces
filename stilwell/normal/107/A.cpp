#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,c;
int a[1005],b[1005];
int ansx[1005],ansy[1005],ansz[1005],tot;
bool init[1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d%d",&u,&v,&c);
		a[u]=v;b[u]=c;init[v]=true;
	}
	for(i=1;i<=n;++i)
	if(!init[i]&&a[i])
	{
		++tot;ansx[tot]=i;ansz[tot]=b[i];
		for(j=i;;j=a[j])
		{
			ansy[tot]=j;
			if(!a[j])break;
			if(b[j]<ansz[tot])ansz[tot]=b[j];
		}
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;++i)printf("%d %d %d\n",ansx[i],ansy[i],ansz[i]);
}