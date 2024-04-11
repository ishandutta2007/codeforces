#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[555555];
long long lsum[555555],rsum[555555];
int st[555555],top;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	top=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[i]<=a[st[top]])
		{
			sum-=a[st[top]]*(st[top]-st[top-1]);
			top--;
		}
		st[++top]=i;
		sum+=a[i]*(i-st[top-1]);
		lsum[i]=sum;
	}
	sum=0;top=0;st[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[i]<=a[st[top]])
		{
			sum-=a[st[top]]*(st[top-1]-st[top]);
			top--;
		}
		st[++top]=i;
		sum+=a[i]*(st[top-1]-i);
		rsum[i]=sum;
	}
//	for(int i=1;i<=n;i++)cerr<<lsum[i]<<' '<<rsum[i]<<endl;
	long long maxx=rsum[1],maxp=1;
	for(int i=2;i<=n;i++)
	{
		if(rsum[i]+lsum[i]-a[i]>maxx)
		{
			maxp=i;
			maxx=rsum[i]+lsum[i]-a[i];
		}
	}
//	cerr<<maxx<<' '<<maxp<<endl;
	for(int i=maxp-1;i>=1;i--)a[i]=min(a[i+1],a[i]);
	for(int i=maxp+1;i<=n;i++)a[i]=min(a[i-1],a[i]);
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}