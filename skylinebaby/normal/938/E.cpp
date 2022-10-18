#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000007ll;
int poow(int x,int n)
{
	if (n==0) return 1;
	if (n==1) return x;
	if (n%2==1) return (x*poow(x,n-1))%N;
	if (n%2==0) 
	{
		int r = poow(x,n/2);
		return (r*r)%N;
	}
}
struct P{
	int x,y;
};
int a[1234567];
P b[1234567];
main()
{
	int n;
	scanf("%lld",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int x = 1;
	for(int i = 1;i<=n;i++)
	{
		x=(x*i)%N;
	}
	sort(a,a+n);
	a[n]=1000000002ll;
	int now = 0;
	int tot = a[0];
	int j = 0;
	for(int i = 0;i<=n;i++)
	{
		if (a[i]>tot)
		{
			b[j++].x=i-now;
			b[j-1].y=tot;
			tot = a[i];
			now = i;
		}
	}
	int acc = 0;
	int ans = 0;
	for(int i = 0;i<j-1;i++)
	{
		int z = (b[i].x*b[i].y*x)%N;
		z = z*poow(n-acc,N-2)%N;
		ans = (ans+z)%N;
		acc += b[i].x;
	}
	printf("%lld\n",ans);
	return 0;
}