#include<cstdio>

using namespace std;

int n,k,a[10010];
double ans,l,r,mid;

int check(double now)
{
	double now1=0.0,now2=0.0;
	for(int i=1;i<=n;i++)
		if(a[i]<now)now1+=now-a[i];
		else now2+=a[i]-now;
	now2=now2*(1-k/100.0);
	if(now2>=now1)return 1;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=0.0;
	r=1000.0;
	while(l+1e-8<r)
	{
		mid=(l+r)/2.0;
		if(check(mid))ans=mid,l=mid+1e-8;
		else r=mid-1e-8;
	}
	printf("%.6lf",ans);
}