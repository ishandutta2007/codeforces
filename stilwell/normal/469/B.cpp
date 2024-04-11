#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,l,r,i,j,k,u,v,ans;
bool a[10005],b[10005],f;

int main()
{
	scanf("%d%d%d%d",&n,&m,&l,&r);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		for(j=u;j<=v;++j)a[j]=true;
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		for(j=u;j<=v;++j)b[j]=true;
	}
	for(i=l;i<=r;++i)
	{
		f=false;
		for(j=0;j<=1000;++j)
		if(a[j+i]&b[j])f=true;
		if(f)++ans;
	}
	printf("%d\n",ans);
}