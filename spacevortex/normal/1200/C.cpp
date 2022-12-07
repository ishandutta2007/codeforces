#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
ll n,m,Q,bl1,bl2,h1,h2;
ll p(ll typ,ll x)
{
	if(typ==1) return (x-1)/h1+1;
	else return (x-1)/h2+1;
}
int main()
{
	ll a,b,c,d;
	n=rd();m=rd();Q=rd();
	bl1=m/__gcd(n,m);bl2=n/__gcd(n,m);
	h1=bl2;h2=bl1;
	while(Q--)
	{
		a=rd();b=rd();c=rd();d=rd();
		if(p(a,b)==p(c,d)) puts("YES");
		else puts("NO");
	}
	return 0;
}