#include <cstdio>
using namespace std;
int n,m,i;
int a[1005],b[1005];
double ans;
double calc(double pre,double r)
{
	if ((int)(r+0.5)==1)
		return -1;
	double ret=pre/(1-1/r);
	if (ret<=pre)
		return -1;
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
		scanf("%d",&b[i]);
	ans=m;
	ans=calc(ans,b[1]);
	for (i=n;i>=2;i--)
	{
		ans=calc(ans,a[i]);
		ans=calc(ans,b[i]);
	}
	ans=calc(ans,a[1]);
	ans-=m;
	if (ans<=0)
		printf("-1\n");
	else
		printf("%.9lf\n",ans);
	return 0;
}