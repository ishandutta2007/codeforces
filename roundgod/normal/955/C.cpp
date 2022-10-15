#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll q,l,r;
set<ll> s;
ll _sqrt(ll x)
{
	ll lb=0,rb=INF+1;
	while(rb-lb>1)
	{
		ll mid=(lb+rb)/2;
		if(mid*mid<=x) lb=mid; else rb=mid;
	}
	return lb;
}
int main()
{
	scanf("%I64d",&q);
	for(ll i=2;i<=1000000;i++)
	{
		ll tt=_sqrt(i);
		if(tt*tt==i) continue;
		ll ps=i*i,res=i*i*i;
		for(;;)
		{
			s.insert(res);
			if((ll)INF*INF/ps<res) break;
			res=res*ps;
		}
	}
	vector<ll> v(s.begin(),s.end());
	for(ll i=1;i<=q;i++)
	{
		scanf("%I64d%I64d",&l,&r);
		ll ans=upper_bound(v.begin(),v.end(),r)-upper_bound(v.begin(),v.end(),l-1);
		ans+=_sqrt(r)-_sqrt(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}