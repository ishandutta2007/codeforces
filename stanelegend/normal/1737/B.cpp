#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

LL t,l,r;

LL calc(LL c)
{
	if(c==0) return 0;
	LL ret=0;
	LL lb=0,ub=1e9,mid;
	while(lb<ub)
	{
		mid=(lb+ub+1)/2;
		if(mid*mid<=c) lb=mid;
		else ub=mid-1;
	}
	ret+=lb;
	lb=0;ub=1e9;
	while(lb<ub)
	{
		mid=(lb+ub+1)/2;
		if(mid*mid+mid<=c) lb=mid;
		else ub=mid-1;
	}
	ret+=lb;
	lb=0;ub=1e9;
	while(lb<ub)
	{
		mid=(lb+ub+1)/2;
		if(mid*(mid+2)<=c) lb=mid;
		else ub=mid-1;
	}
	ret+=lb;
	return ret;
}

int main()
{
	cin>>t;
	rep(tn,t)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}