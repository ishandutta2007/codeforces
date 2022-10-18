#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=200010;
int n,m;
struct eg2
{
	int a,b,w;
	inline bool operator<(const eg2 &e)const{return w>e.w;}
}e[MAXN];
int pa[MAXN],siz[MAXN];
int find(int x)
{
	return pa[x]?(pa[x]=find(pa[x])):x;
}
int main()
{
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int pu=find(e[i].a),pv=find(e[i].b);
		if(pu==pv&&siz[pu])
		{
			ans+=e[i].w;
			siz[pu]--;
		}
		else if(siz[pu]||siz[pv])
		{
			pa[pu]=pv;
			siz[pv]+=siz[pu]-1;
			ans+=e[i].w;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}