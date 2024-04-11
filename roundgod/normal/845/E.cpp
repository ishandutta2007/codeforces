#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,k,p[MAXN][2];
vector<ll> Points;
vector<P> Segments;
bool C(ll t,ll x,ll y,ll n,ll m)
{
	Points.clear();
	Points.push_back(1);
	Points.push_back(n);
	for(ll i=0;i<k;i++)
	{
		if(p[i][x]-t>1) 
		{
			Points.push_back(p[i][x]-t);
			Points.push_back(p[i][x]-t-1);
		}
		if(p[i][x]+t<n) 
		{
			Points.push_back(p[i][x]+t);
			Points.push_back(p[i][x]+t+1);
		}
	}
	sort(Points.begin(),Points.end());
	Points.erase(unique(Points.begin(),Points.end()),Points.end());
	ll minp=n,maxp=1;
	for(ll i=0;i<Points.size();i++)
	{
		Segments.clear();
		for(ll j=0;j<k;j++)
			if(abs(p[j][x]-Points[i])<=t)
				Segments.push_back(P(p[j][y]-t,p[j][y]+t+1));
		sort(Segments.begin(),Segments.end());
		ll last=1;
		for(ll j=0;j<Segments.size();j++)
		{
			if(Segments[j].F>last) break;
			last=Segments[j].S;
		}
		if(last<=m)
		{
			minp=min(minp,Points[i]);
			maxp=max(maxp,Points[i]);
		}
	}
	return maxp-minp<=2*t;
}
ll abs(ll x){return max(x,-x);}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(ll i=0;i<k;i++)
		scanf("%I64d%I64d",&p[i][0],&p[i][1]);
	ll l=-1,r=1e9+7;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(C(mid,0,1,n,m)&&C(mid,1,0,m,n)) r=mid; else l=mid;
	}
	printf("%I64d\n",r);
	return 0;
}