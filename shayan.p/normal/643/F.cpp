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

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxp=150;
const ll mod=4294967296;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

ll calc_cnk(ll n,ll k){
	if(n<k)return 0;
	if(k==0)return 1;
	vector<ll>N;
	REP(i,k)
		N.PB(n-i);
	FOR(i,1,k){
		ll cop=i;
		REP(j,sz(N)){
			if(cop==1)
				break;
			if(N[j]==1)
				continue;
			ll g=gcd(N[j],cop);
			cop/=g;
			N[j]/=g;
		}
	}
	ll ans=1;
	REP(i,sz(N))
		ans=(ans*N[i])%mod;
	return ans;
}

ll cnk[maxp];

int main(){
	ll n,p,q;cin>>n>>p>>q;
	FOR(i,0,min(p,n-1))
		cnk[i]=calc_cnk(n,i);
	ll Ans=0;
	FOR(i,1,q){
		ll ans=0;
		ll tavan=1;
		FOR(j,0,min(p,n-1)){
			ans+=(tavan*cnk[j]);
			ans%=mod;
			tavan*=i;
			tavan%=mod;
		}
		ans=(ans*i)%mod;
		ans+=mod;
		ans%=mod;
		Ans^=ans;
	}
	cout<<Ans;
}