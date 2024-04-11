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
const ll maxn=3010;
const ll mod=1e9+7;

ll dp[maxn][maxn],sm[maxn][maxn],n,k;
ll fac[maxn],ifac[maxn],rfac[maxn];
vector<ll>v[maxn];

void dfs(ll u){
    REP(i,sz(v[u])){
	ll y=v[u][i];
	dfs(y);
	FOR(j,1,n){
	    dp[u][j]=(dp[u][j]*sm[y][j])%mod;
	}
    }
    FOR(i,1,n){
	sm[u][i]=(sm[u][i-1]+dp[u][i])%mod;
    }
}

ll tavan(ll a,ll b){
    ll an=1;
    while(b>0){
	if(b%2) an=(an*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return an;
}

void pre(){
    rfac[0]=fac[0]=1;
    FOR(i,1,n)
	fac[i]=(fac[i-1]*i)%mod;
    ifac[n]=tavan(fac[n],mod-2);
    FORD(i,n-1,0)
	ifac[i]=(ifac[i+1]*(i+1))%mod;
    FOR(i,1,n)
	rfac[i]=(rfac[i-1]*(k-i+1))%mod;
}

inline ll C(ll x){
    if(k<x)return 0;
    return (rfac[x]*ifac[x])%mod;
}
inline ll C(ll N,ll K){
    if(N<K)return 0;
    return (((fac[N]*ifac[K])%mod)*ifac[N-K])%mod;
}

int main(){
    REP(i,maxn){
	REP(j,maxn){
	    dp[i][j]=1;
	}
    }
    
    cin>>n>>k;

    pre();
    
    FOR(i,2,n){
	ll x;cin>>x;
	v[x].PB(i);
    }

    dfs(1);

    FOR(i,1,n){
	FOR(j,1,i-1){
	    dp[1][i]=(((dp[1][i]-C(i-1,j-1)*dp[1][j])%mod)+mod)%mod;
	}
    }

    ll ans=0;
    FOR(i,1,n){
	ans=(ans+C(i)*dp[1][i])%mod;
    }

    cout<<ans;
}