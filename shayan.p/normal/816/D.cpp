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

const ll inf=1e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll n,N;
ll fact[maxn],a[maxn];

pll gcd(ll a,ll b) {if(b==0) return MP(a,0);pll p=gcd(b,a%b);return MP(p.S,p.F-((a/b)*p.S));}
ll varoon(ll a) {return (gcd(a,mod).F+mod)%mod;}
ll C(ll n,ll k){
	return (fact[n]*((varoon(fact[k])*varoon(fact[n-k]))%mod))%mod;
}

ll f(ll q){
	ll ans=0;
	FOR(i,1,N){
		ans=(ans+C(N-1,i-1)*a[2*i+q])%mod;
	}
	return ans;
}

int main(){
	fact[0]=1;FOR(i,1,maxn-1)fact[i]=(fact[i-1]*i)%mod;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		a[i]%=mod;
	}
	if(n%2){
		ll manfi=1;
		FOR(i,1,n-1){
			a[i]=(a[i]+(manfi*a[i+1]))%mod;
			manfi*=-1;
		}
		n--;
	}
	if(n<10){
		ll manfi=1;
		REP(i,n-1){
			FOR(j,1,n-i-1){
				a[j]=(a[j]+(manfi*a[j+1]))%mod;
				manfi*=-1;
			}
		}
		cout<<((a[1]%mod)+mod)%mod;
		return 0;
	}
	N=n/2;
	ll manfi=((n%4==0)?-1:1);
	cout<<(((f(-1)+(manfi*f(0)))%mod)+mod)%mod;
}