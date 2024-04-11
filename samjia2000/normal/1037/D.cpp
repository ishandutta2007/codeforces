

#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,m,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],a[MAXN],b[MAXN],f[MAXN];
void dfs(int x)
{
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		dfs(p[i]);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)b[a[i]]=i;
	dfs(1);
	for(i=2;i<=n;i++)if(b[f[a[i]]]<b[f[a[i-1]]])break;
	if(i>n)puts("Yes");
	else puts("No");
	return 0;
}