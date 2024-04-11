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
map<pair<ll,ll>,vector<ll>> m;
int _runtimeTerror_()
{
	ll n,i,q,c,j;
	cin>>n>>q>>c;
	ll pr[101][101][c+1];
	mem0(pr);
	for(i=0;i<n;++i)
	{
		ll x,y,s;
		cin>>x>>y>>s;
		pr[x][y][s]++;
	}
	for(i=1;i<=100;++i)
	{
		for(j=1;j<=100;++j)
		{
			for(ll k=0;k<=c;++k)
				pr[i][j][k]+=pr[i][j-1][k];
		}
	}
	while(q--)
	{
		ll x1,x2,y1,y2,t;
		cin>>t>>x1>>y1>>x2>>y2;
		ll ans[c+1]={0},val[c+1]={0};
		for(i=x1;i<=x2;++i)
		{
			for(j=0;j<=c;++j)
			{
				ans[j]+=pr[i][y2][j]-pr[i][y1-1][j];
			}
		}
		t%=c+1;
		for(i=0;i<=c;++i)
			val[(i+t)%(c+1)]=ans[i];
		ll print=0;
		for(i=0;i<=c;++i)
			print+=i*val[i];
		cout<<print<<endl;
	}
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