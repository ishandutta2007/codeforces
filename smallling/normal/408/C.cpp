#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int sqr(int x)
{
	return x*x;
}

int aa,bb,a[3][1001],a1,i,o,b[3][1001],b1,j;

int main()
{
	scanf("%d%d",&aa,&bb);
	for(i=1;i<aa;i++)
	{
		o=sqr(trunc(sqrt(sqr(aa)-sqr(i))));
		if(o==sqr(aa)-sqr(i))a[1][++a1]=i,a[2][a1]=trunc(sqrt(o));
	}
	for(i=1;i<bb;i++)
	{
		o=sqr(trunc(sqrt(sqr(bb)-sqr(i))));
		if(o==0)continue;
		if(o==sqr(bb)-sqr(i))b[1][++b1]=i,b[2][b1]=trunc(sqrt(o));
	}
	for(i=1;i<=a1;i++)
	for(j=1;j<=b1;j++)
	if(a[1][i]!=-b[1][j]&&a[2][i]!=b[2][j])
	{
		if(sqr(a[1][i]+b[1][j])+sqr(a[2][i]-b[2][j])==sqr(aa)+sqr(bb))
		{
			printf("YES\n");
			printf("0 0\n");
			printf("%d %d\n",a[1][i],a[2][i]);
			printf("%d %d\n",-b[1][j],b[2][j]);
			return 0;
		}
	}
	printf("NO");
}