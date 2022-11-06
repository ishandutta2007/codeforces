#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long int ll;

ll n,m,k,l,r,mid;

ll min(ll x,ll y)
{
	if (x>y) return y; else return x;
}

ll cnt(ll x)
{
	ll t=0;
	for (int i=1;i<=n;i++)
	    t=t+min(x/i,m);
	return t;
}

int main()
{
	scanf("%d%d%I64d",&n,&m,&k);
	l=1,r=n*m,mid=(l+r)/2;
	while (l<=r)
	{
		if (cnt(mid)<k) l=mid+1; else r=mid-1;
		mid=(l+r)/2;
	}
	r--;
	while (cnt(r)<k) r++;
	printf("%I64d\n",r);
	return 0;
}