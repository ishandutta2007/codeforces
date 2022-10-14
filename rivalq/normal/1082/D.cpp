#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}

int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	ll a[n+1],count=0,sum=0;
	vector<ll> deg,rem;
	for(i=1;i<=n;++i)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]==1){++count;deg.pb(i);}
		else rem.pb(i);
	}
	if(sum<2*(n-1))
	{
		cout<<"NO\n";return 0;
	}
	cout<<"YES ";
	if(count<=2)
		cout<<n-1;
	else
		cout<<n-1-(count-2);
	cout<<endl;
	sort(all(rem),[&](ll aa,ll bb){return a[aa]>a[bb];});
	if(count==1)
		rem.pb(deg[0]);
	else if(count>=2)
	{
		rem.pb(deg[0]);rem.insert(rem.begin(),deg[1]);
	}
	for(auto j:rem)
		a[j]-=2;
	vector<pair<ll,ll>> ans;
		for(i=0;i<sz(rem)-1;++i)
		ans.pb({rem[i],rem[i+1]});
	if(count>2)
	{
		ll curr1=2,curr2=1;
		while(curr1<sz(deg))
		{
			if(a[rem[curr2]]==0)
				++curr2;
			--a[rem[curr2]];
			ans.pb({rem[curr2],deg[curr1]});
			++curr1;
		}
	}
	cout<<sz(ans)<<endl;
	for(auto j:ans)
		cout<<j.F<<" "<<j.S<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}