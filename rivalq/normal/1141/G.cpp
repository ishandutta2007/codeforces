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
const int N=200005;
vector<pair<ll,ll>> v[N];
bool vis[N];
ll ans[N];
set<ll> s;
void dfs(ll so,ll pcol)
{
	ll curr=1;
	bool var=false;
	if(s.count(so))
	{
		var=true;
	}
	vis[so]=true;
	for(auto j:v[so])
	{
		if(!vis[j.F])
		{
			if(curr==pcol)++curr;
			if(var)
			{
				ans[j.S]=1;
			}
			else
			{
				ans[j.S]=curr;
			}
			dfs(j.F,ans[j.S]);
			++curr;
		}
	}
}
int _runtimeTerror_()
{
	ll n,k,i;
	cin>>n>>k;
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb({y,i});v[y].pb({x,i});
	}
	ll a[n];
	for(i=0;i<n;++i)a[i]=i+1;
	sort(a,a+n,[&](ll a,ll b){return sz(v[a])>sz(v[b]);});
	for(i=0;i<k;++i)
		s.insert(a[i]);
	dfs(a[0],-1);
	set<ll> sett;
	for(i=0;i<n-1;++i)
		sett.insert(ans[i]);
	cout<<sz(sett)<<endl;
	for(i=0;i<n-1;++i)
		cout<<ans[i]<<" ";
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