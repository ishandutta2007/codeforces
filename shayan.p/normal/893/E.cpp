#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e6+100,mod=1e9+7;
ll par[maxn],tw[maxn],fact[maxn];
map<ll,ll>primes;
inline void tajzie(ll num){
	if(num==1)return;
	if(par[num]==0){primes[num]++;return;}
	primes[par[num]]++;
	tajzie(num/(par[num]));
}
inline pll gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}
inline ll varoon(ll a) {return ((gcd(a,mod).F)%mod+mod)%mod;}
ll C(ll n,ll k){
	if(n<k)return 0;
	ll a=fact[n],b=fact[k],c=fact[n-k];
	b=varoon(b);c=varoon(c);
	return (((a*b)%mod)*c)%mod;
}
inline ll calc(ll num,ll y){return C(num+y-1,y-1);}
int main()
{
	for(ll i=2;i<maxn-5;i++){
		if(par[i]==0){
			for(ll j=i*i;j<maxn-5;j+=i)par[j]=i;
		}
	}
	tw[0]=1;for(ll i=1;i<maxn;i++)tw[i]=(tw[i-1]*2)%mod;
	fact[0]=1;for(ll i=1;i<maxn;i++)fact[i]=(fact[i-1]*i)%mod;
	ll q;cin>>q;
	for(ll i=0;i<q;i++){
		ll x,y;cin>>x>>y;
		primes.clear();
		tajzie(x);
		ll ans=tw[y-1];
		for(map<ll,ll>::iterator it=primes.begin();it!=primes.end();it++){
			ans=(ans*calc((*it).S,y))%mod;
		}
		cout<<ans<<endl;
	}
}