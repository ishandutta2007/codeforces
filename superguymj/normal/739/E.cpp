#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005,INF=1000000000;
const double eps=1e-10;
int n,x,y;
double a[N],b[N];
struct data
{
	double ans;
	int x,y;
	void max(double a,int b,int c)
	{
		if(ans<a) ans=a,x=b,y=c;
	}
} f[N];

void dp(double x,double y)
{
	rep(i,1,n)
	{
		f[i]=f[i-1];
		f[i].max(f[i-1].ans+a[i]-x,f[i-1].x+1,f[i-1].y);
		f[i].max(f[i-1].ans+b[i]-y,f[i-1].x,f[i-1].y+1);
		f[i].max(f[i-1].ans+a[i]+b[i]-a[i]*b[i]-x-y,f[i-1].x+1,f[i-1].y+1);
	}
}

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	rep(i,1,n) scanf("%lf",&a[i]);
	rep(i,1,n) scanf("%lf",&b[i]);
	double l1=0,r1=1,mid1;
	double l2,r2,mid2;
	while(r1-l1>eps)
	{
		l2=0,r2=1,mid1=(l1+r1)/2;
		while(r2-l2>eps)
		{
			mid2=(l2+r2)/2,dp(mid1,mid2);
			f[n].y<=y?r2=mid2:l2=mid2;
		}
		dp(mid1,r2),f[n].x<=x?r1=mid1:l1=mid1;
	}
	dp(r1,r2),printf("%.10lf\n",f[n].ans+r1*x+r2*y);
	return 0;
}