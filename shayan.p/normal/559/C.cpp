// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2010;
const ll maxh=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll dp[maxn];
ll fac[maxh],ifac[maxh];
pll p[maxn];

inline ll C(ll n,ll k){
	if(n<k)return 0;
	return (((fac[n]*ifac[k])%mod)*ifac[n-k])%mod;
}

ll tavan(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}

void pre(){
	fac[0]=1;
	FOR(i,1,maxh-1)
		fac[i]=(fac[i-1]*i)%mod;
	ifac[maxh-1]=tavan(fac[maxh-1],mod-2);
	FORD(i,maxh-2,0)
		ifac[i]=(ifac[i+1]*(i+1))%mod;
}

int main(){
	pre();
	ll h,w,n;cin>>h>>w>>n;
	REP(i,n)
		cin>>p[i].F>>p[i].S;
	sort(p,p+n);
	p[n]=MP(h,w);
	FOR(i,0,n){
		dp[i]=C(p[i].F+p[i].S-2,p[i].F-1);
		REP(j,i){
			if(p[j].S<=p[i].S)
				dp[i]=(dp[i]-dp[j]*C(p[i].F-p[j].F+p[i].S-p[j].S,p[i].F-p[j].F))%mod;
		}
	}
	cout<<(dp[n]+mod)%mod;
}