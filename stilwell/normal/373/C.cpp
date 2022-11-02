#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int fa[500005],son[500005];
int a[500005],b[500005];
int n,i,j,k,ans;

int get(int p)
{
	if(fa[p]==p)return p;
	fa[p]=get(fa[p]);
	return fa[p];
}

bool find(int x)
{
	if(get(b[x])==n+1)return false;
	son[fa[b[x]]]=x;
	fa[fa[b[x]]]=fa[b[x]]+1;
	return true;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[n+1]=a[n]*2;
	for(i=1;i<=n;++i)
	for(b[i]=b[i-1];b[i]<=n;++b[i])
	if(a[b[i]]/2>=a[i])break;
	for(i=1;i<=n+1;++i)fa[i]=i;
	ans=n;
	for(i=1;i<=n;++i)
	if(!son[i])
	{
		if(find(i))--ans;
	}
	else
	{
		if(find(son[i]))
		{
			if(find(i))--ans;
		}
	}
	printf("%d\n",ans);
}