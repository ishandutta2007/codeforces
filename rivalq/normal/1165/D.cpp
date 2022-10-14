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
bool is_prime(ll n)
{
	ll k= sqrt(n);
	for(ll i=2;i<=k;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
#define runSieve
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=1000000)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	ll a[n];
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	if(n==1)
	{
		if(is_prime(a[0]))
		{
			cout<<a[0]*a[0]<<endl;return 0;
		}
		else {
			cout<<-1<<endl;return 0;
		}
	}
	ll ans=a[0]*a[n-1];
	for(i=1;i<n/2;++i)
	{
		ll kk=a[i]*a[n-1-i];
		if(kk!=ans)
		{
			cout<<-1<<endl;return 0;
		}
	}
	if(n&1)
	{
		ll kk=a[n/2]*a[n/2];
		if(kk!=ans)
		{
			cout<<-1<<endl;return 0;
		}
	}
	ll k=ans,count=1;
	for(ll i=2;i*i<=k;++i)
	{
		if(k%i==0)
		{
			ll cc=0;
			while(k%i==0)
			{
				++cc;
				k/=i;
			}
			count*=(cc+1);
		}
	}
	if(k!=1)count*=2;
	if(count-2==n)
	{
		cout<<ans<<endl;
	}
	else
	cout<<-1<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}