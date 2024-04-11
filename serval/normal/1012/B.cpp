#include <cstdio>
using namespace std;
int n,m,q,x,y,ans;
int fa[400005];
int getf(int u)
{
	return fa[u]==0?u:fa[u]=getf(fa[u]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	ans=n+m-1;
	while (q--)
	{
		scanf("%d%d",&x,&y);
		y+=n;
		x=getf(x);
		y=getf(y);
		if (x!=y)
		{
			ans--;
			fa[x]=y;
		}
	}
	printf("%d\n",ans);
	return 0;
}