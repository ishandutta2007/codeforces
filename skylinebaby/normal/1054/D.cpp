#include<bits/stdc++.h>
using namespace std;
int a[211234];
int b[211234];
long long solve(long long n)
{
	long long x = n/2;
	long long y = n - x;
	return (x)*(x-1)/2 + (y)*(y-1)/2;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	int s = (1<<k) - 1;
	long long ans = (long long)n*(n+1)/2;
	b[0] = 0;
	for(int i = 1;i<=n;i++) 
	{
		b[i] = b[i-1]^a[i];
		if(b[i]*2>s) b[i]^=s;
	}
	sort(b,b+1+n);
	for(int i = 0;i<=n;i++)
	{
		int pos = i;
		long long cur = 1;
		//printf("%d\n",i);
		while(pos<n&&b[pos]==b[pos+1])
		{
			pos++;
			cur++;
			//printf("%d\n",pos);
		}
		ans -= solve(cur);
		i = pos;
	}
	printf("%lld\n",ans);
	return 0;
}