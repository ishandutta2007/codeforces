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

const ll mod=1e9+7;
const ll maxn=3010;

ll fac[maxn],ifac[maxn];

inline ll C(ll n,ll k){
	if(n<k||k<0)return 0;
	return (((fac[n]*ifac[k])%mod)*ifac[n-k])%mod;
}

ll tavan(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}

void pre(){
	fac[0]=ifac[0]=1;
	FOR(i,1,maxn-1)
		fac[i]=(fac[i-1]*i)%mod;
	ifac[maxn-1]=tavan(fac[maxn-1],mod-2);
	FORD(i,maxn-2,0)
		ifac[i]=(ifac[i+1]*(i+1))%mod;
}

int main(){
	pre();
	ll t;cin>>t;
	while(t--){
		string ss;cin>>ss;
		ll y=0,n=sz(ss);
		REP(i,n)
			y+=ss[i]-'a';
		ll ans=0;
		FOR(k,0,n){
			ans=(ans+(((k%2)?-1:1)*C(n,k)*C(y+n-1-(26*k),n-1)))%mod;
		}
		ans=(ans-1+mod)%mod;
		cout<<ans<<endl;
	}
}