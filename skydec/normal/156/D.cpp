#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
int n,m,k;int size[MAXN],fa[MAXN];
int get(int x){return (x==fa[x])?x:fa[x]=get(fa[x]);}
void Union(int a,int b){a=get(a);b=get(b);if(a!=b)fa[a]=b,size[b]+=size[a];}
int main()
{
	scanf("%d%d%d",&n,&m,&k);int ret=1;int kuai=0;
	for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
	for(int i=1;i<=m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);Union(a,b);
	}
	for(int i=1;i<=n;i++)
	if(fa[i]==i)kuai++,ret=ret*1ll*size[i]%k;
	for(int i=1;i<=kuai-2;i++)ret=ret*1ll*n%k;
	if(kuai==1)ret=1%k;printf("%d\n",ret);
	return 0;
}