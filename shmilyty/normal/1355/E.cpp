#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,R,M,h[100001],l=114514114514,r;
int f(int x)
{
	int a=0,r=0,m;
	for(int i=1;i<=n;i++)
	{
		r+=max(h[i]-x,0ll);
		a+=max(x-h[i],0ll);
	}
	m=min(a,r);
	return min(a*A+r*R,m*M+A*(a-m)+R*(r-m));
}
signed main()
{
	scanf("%lld %lld %lld %lld",&n,&A,&R,&M);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		l=min(l,h[i]);
		r=max(r,h[i]);
	}
//	cout<<l<<" "<<r<<endl;
	while(r-l>3)
	{
		int mid1=l+(r-l)/3;
		int mid2=r-(r-l)/3;
		if(f(mid1)>f(mid2))
			l=mid1;
		else
			r=mid2;
	}
	cout<<min(f(l),min(f(l+1),min(f(l+2),f(l+3))));
	return 0;
}