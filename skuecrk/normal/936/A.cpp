#include<cstdio>
#include<iostream>
using namespace std;
typedef long double ld;
typedef long long ll;
int main()
{
	ll k,d,t;int i;ld l,r,mid,x;
	cin>>k>>d>>t;
	d=(k+d-1)/d*d-k;
	for(l=0,r=2*t,i=1;i<=1e6;++i)
	{
		mid=(l+r)/2;
		x=ll(mid)/(k+d)*(k+d);
		if(x/(k+d)*(ld(k)/t+ld(d)/2/t)+(mid-x<k?ld(mid-x)/t:ld(k)/t+ld(mid-x-k)/2/t)<1)
			l=mid;else r=mid;
	}
	printf("%.10lf",(double)r);
}