#include <stdio.h>
#include <stdlib.h>
using namespace std;

int fa[300005],ans[300005];
int n,m,i,j,k,x,l,r;

int get(int p)
{
	if(fa[p]==p)return p;
	fa[p]=get(fa[p]);
	return fa[p];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+1;++i)fa[i]=i;
	for(;m;--m)
	{
		scanf("%d%d%d",&l,&r,&x);
		for(i=get(l);i<=r;)
		if(i!=x)
		{
			ans[i]=x;
			fa[i]=i+1;
			i=get(i);
		}else i=get(i+1);
	}
	printf("%d",ans[1]);
	for(i=2;i<=n;++i)printf(" %d",ans[i]);
	printf("\n");
	//system("pause");
}