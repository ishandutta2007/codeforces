// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;/////// momkene bazam kam biad
const ll mod=1e9+7;
const ll maxn=40;

ll a[maxn];
ll dp[maxn][maxn];// ba estefade az i bit khodemoon ta bit j L ro besazim

int main(){
	ll n,L;cin>>n>>L;
	REP(i,n)
		cin>>a[i];
	REPD(i,n-1)
		a[i]=min(a[i],a[i+1]);
	REP(i,n){
		if(i==0)continue;
		a[i]=min(a[i],2*a[i-1]);
	}
	FOR(i,n,30){
		a[i]=2*a[i-1];
	}
	ll ans=0;

	REP(i,31){
		if((L>>i)&1)
			ans+=a[i];
	}
	
	REP(i,31){//start point
		ll num=0;
		if((L>>i)&1)continue;
		num+=a[i];
		FOR(j,i+1,30){
			if((L>>j)&1)
				num+=a[j];
		}
		ans=min(ans,num);
	}
	cout<<ans;
}