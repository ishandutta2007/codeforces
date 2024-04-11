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

const ll maxn=310;
const ll mod=1e9+7;

ll p[maxn],n;
ll dp[maxn][maxn];
ll fac[maxn],ifac[maxn];

ll tavan(ll a,ll b){
	if(b==0)return 1;
	return ((b%2?a:1)*tavan((a*a)%mod,b/2))%mod;
}

void input_and_reform(){
	ll a[maxn];
	bool mark[maxn];
	memset(mark,0,sizeof mark);
	ll t;cin>>t;
	REP(i,t)
		cin>>a[i];
	REP(i,t){
		if(!mark[i]){
			ll cnt=1;
			mark[i]=1;
			FOR(j,i+1,t-1){
				if(!mark[j]){
					ll num=a[i]*a[j];
					ll sq=sqrt(num);
					if((sq*sq)==num){
						mark[j]=1;
						cnt++;
					}
				}
			}
			p[n++]=cnt;
		}
	}
}

void pre(){
	ifac[0]=fac[0]=1;
	FOR(i,1,maxn-1)
		fac[i]=(fac[i-1]*i)%mod;
	ifac[maxn-1]=tavan(fac[maxn-1],mod-2);
	FORD(i,maxn-2,1)
		ifac[i]=(ifac[i+1]*(i+1))%mod;
}

inline ll C(ll n,ll k){
	if(n<k)return 0;
	if(k<0)return 0;
	return (((fac[n]*ifac[k])%mod)*ifac[n-k])%mod;
}

int main(){
	input_and_reform();
	pre();
	dp[0][p[0]-1]=1;
	ll tot=p[0];
	
	FOR(i,1,n-1){
		FOR(j,0,maxn-1){
			FOR(ba,0,tot){
				ll sm=0;
				FOR(bl,1,p[i]){
					ll num=(((C(p[i]-1,bl-1)*C(ba,ba+p[i]-bl-j))%mod)*C(tot+1-ba,bl+bl+j-ba-p[i]))%mod;
					sm=(sm+num)%mod;
				}
				sm=(sm*dp[i-1][ba])%mod;
				dp[i][j]+=sm;
				dp[i][j]%=mod;
			}
		}
		tot+=p[i];
	}
	ll ans=dp[n-1][0];
	REP(i,n)
		ans=(ans*fac[p[i]])%mod;
	cout<<ans;
}