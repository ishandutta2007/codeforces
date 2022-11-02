#include<cstdio>
#include<cmath>

int n,m;
double ans,lastans,now;

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		now=pow(i*1./m,n);
		ans+=(now-lastans)*i;
		lastans=now;
	}
	printf("%.12lf",ans);
}