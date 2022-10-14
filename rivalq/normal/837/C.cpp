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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }


int _runtimeTerror_()
{
	ll n,a,b;
	ll i;
	cin>>n>>a>>b;
	ll x[n],y[n];
	for(i=0;i<n;++i)
		cin>>x[i]>>y[i];
	ll j;
	ll ans=0;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(i==j)
				continue;
			if(x[i]+x[j]<=a && y[i]<=b && y[j]<=b)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(x[i]+y[j]<=a && y[i]<=b && x[j]<=b)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(x[i]+x[j]<=b && y[i]<=a && y[j]<=a)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(x[i]+y[j]<=b && y[i]<=a && x[j]<=a)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(y[i]+x[j]<=a && x[i]<=b && y[j]<=b)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(y[i]+y[j]<=a && x[i]<=b && x[j]<=b)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(y[i]+x[j]<=b && x[i]<=a && y[j]<=a)
				amax(ans,x[i]*y[i]+x[j]*y[j]);
			if(y[i]+y[j]<=b && x[i]<=a && x[j]<=a)
				amax(ans,x[i]*y[i]+x[j]*y[j]);


		}
	}
	cout<<ans<<endl;
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
	cerr<<"\n"<<_time_;
	return 0;
}