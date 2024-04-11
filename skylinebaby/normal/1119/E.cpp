#include<bits/stdc++.h>
using namespace std;
long long a[312345];
long long c[313245];
long long b[312345];
int n;
int solve(long long x)
{
	int pos = n-1;
	for(int i = 0;i<n;i++) c[i] = a[i];
	memset(b,0,sizeof(b));
	long long cur = 0;
	while(pos>=0&&cur<x)
	{
		if(c[pos]>=2)
		{
			if(2*(x-cur)>=c[pos])
			{
				b[pos] += c[pos]/2;
				c[pos] %=2;
				cur += b[pos];
			}
			else
			{
				c[pos] -= 2*(x-cur);
				b[pos] += x-cur;
				cur = x;  
			}	
		}
		else pos--;	
	}
	//if(x==3)for(int i = 0;i<n;i++)printf("bc %lld %lld\n",b[i],c[i]);
	
	if(cur<x)
	{
		return 0;
	}
	int flag = 0;
	long long xx = 0;
	long long yy = 0;
	for(int i = 0;i<n;i++)
	{
		xx+=c[i];
		yy+=b[i];
		if(xx<yy)
		{
			flag = 1;
			//if (x==3) printf("%d\n",i);
		}
	}
	if(flag==1) return 0;
	//printf("WJEIJE %d\n",x);
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i<n;i++) 
	{
		scanf("%lld",&a[i]);
	}
	long long ans = 0;
	long long d = 50;
	while(d--)
	{
		if(solve(ans+(1ll<<d)))
		{
			ans +=(1ll<<d);
		}
	}
	printf("%lld\n",ans);
	return 0;
}