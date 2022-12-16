// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e6+10;
const ll mod=998244353;

ll tavan(ll a,ll b){
    a%=mod;
    ll ans=1;
    while(b>0){
	if(b%2) ans=(ans*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return ans;
}

ll rev(ll num){
    return tavan(num,mod-2);
}

ll fac[maxn],ifac[maxn];

int main(){
    fac[0]=1;
    FOR(i,1,maxn-1){
	fac[i]=(i*fac[i-1])%mod;
    }
    ifac[maxn-1]=rev(fac[maxn-1]);
    FORD(i,maxn-2,0){
	ifac[i]=(ifac[i+1]*(i+1))%mod;
    }
    
    ll n;cin>>n;
    ll ans=((-2)*tavan(3,n*n)*(tavan(-rev(tavan(3,n-1))+1,n)-1))%mod;
    FOR(i,1,n){
	ll A=(i%2?1:-1)*tavan(3,n*(n-i)+1);
	ll B=tavan((-rev(tavan(3,n-i))+1),n)-1;
	ll C=(((fac[n]*ifac[i])%mod)*ifac[n-i])%mod;
	ans=(ans+((A*B)%mod)*C)%mod;
    }
    cout<<(ans+mod)%mod;
}