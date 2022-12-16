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
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll open[maxn],close[maxn];

ll fact[maxn];
ll fact_rev[maxn];

pll gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}

inline ll rev(ll a){
	return (gcd(a,mod).F+mod)%mod;
}

inline ll C(ll n,ll k){
	if(n<k)return 0;
	return (((fact[n]*fact_rev[k])%mod)*fact_rev[n-k])%mod;
}

int main(){
	fact[0]=1;
	FOR(i,1,maxn-1)
		fact[i]=(fact[i-1]*i)%mod;
	FOR(i,0,maxn-1)
		fact_rev[i]=rev(fact[i]);
		
	string s;cin>>s;
	REP(i,sz(s)){
		ll bef=(i==0?0:open[i-1]);
		open[i]=bef+(s[i]=='(');
	}
	REPD(i,sz(s)){
		close[i]=close[i+1]+(s[i]==')');
	}
	ll ans=0;
	REP(i,sz(s)){
		if(s[i]=='('){
			ans+=C(open[i]+close[i]-1,open[i]);
			ans%=mod;
		}
	}
	cout<<ans;
}