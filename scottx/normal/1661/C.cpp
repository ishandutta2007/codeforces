#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const long long inf=9e18;
int n,v[N],m;
long long r;
long long dp(int s)
{
	long long c0=0,c1=0,c2=0;
	for(int i=1;i<=n;i++)
	{
		c1+=(s-v[i])%2;
		c2+=(s-v[i])/2;
	}
	if(c2>=c1+2)
		c0=(c2-c1-2)/3+1;
	long long c4=max((c1+2*c0)*2-1,(c2-c0)*2);
	return c4;
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	m=0;
	r=inf;
	for(int i=1;i<=n;i++)
		m=max(m,v[i]);
	for(int i=0;i<=3;i++)
	{
		long long w=dp(m+i);
		if(w<r)
			r=w;
	}
	printf("%lld\n",r);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}