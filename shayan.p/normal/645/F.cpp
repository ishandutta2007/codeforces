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
#define FORK(i,a,b,c) for(int i=int(a);i<=int(b);i+=int(c))
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e6+10;
const ll mod=1e9+7;

vector<ll>dv[maxn];
ll h[maxn],cof[maxn],ANS,k;
ll fac[maxn],ifac[maxn];

inline ll C(ll N,ll K){
    if(N<K)return 0;
    return (((fac[N]*ifac[K])%mod)*ifac[N-K])%mod;
}

void add_num(ll x){
    REP(i,sz(dv[x])){
	ll y=dv[x][i];
	ANS=(ANS+cof[y]*(C(h[y]+1,k)-C(h[y],k)))%mod;
	h[y]++;
    }
}

ll tavan(ll a,ll b){
    ll an=1;
    while(b>0){
	if(b%2) an=((an)*(a))%mod;
	a=((a)*(a))%mod;
	b/=2;
    }
    return an;
}

void pre(){
    FOR(i,1,maxn-1){
	FORK(j,i,maxn-1,i){
	    dv[j].PB(i);
	}
    }
    
    fac[0]=1;
    FOR(i,1,maxn-1)
	fac[i]=(ll(i)*ll(fac[i-1]))%mod;
    ifac[maxn-1]=tavan(fac[maxn-1],mod-2);
    FORD(i,maxn-2,0)
	ifac[i]=(ll(ifac[i+1])*ll(i+1))%mod;

    FOR(i,1,maxn-1){
	cof[i]=i;
	REP(j,(sz(dv[i])-1)){
	    cof[i]-=cof[dv[i][j]];
	}
    }
    
}

int main(){
    pre();
    ll n,q;scanf("%lld%lld%lld",&n,&k,&q);
    REP(i,n){
        ll x;scanf("%lld",&x);
	add_num(x);
    }
    REP(i,q){
	ll x;scanf("%lld",&x);
	add_num(x);
	printf("%lld\n",((ANS+mod)%mod));
    }
}