#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long a[200020];
double L,R,mid1,mid2,nowans,now;

double calc(double x)
{
	nowans=0,now=0;
	for(int i=1;i<=n;i++)
	{
		now+=a[i]-x;
		if(now<0)now=0;
		nowans=max(nowans,now);
	}
	now=0;
	for(int i=1;i<=n;i++)
	{
		now+=x-a[i];
		if(now<0)now=0;
		nowans=max(nowans,now);
	}
	return nowans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	L=1e19;R=-1e19;
	for(int i=1;i<=n;i++)
		L=min(L,1.*a[i]),R=max(R,1.*a[i]);
	for(int i=1;i<=200;i++)
	{
		mid1=(L*2+R)/3;
		mid2=(L+R*2)/3;
		if(calc(mid1)>calc(mid2))L=mid1;
		else R=mid2;
	}
	printf("%.10lf\n",calc((L*2+R)/3));
}