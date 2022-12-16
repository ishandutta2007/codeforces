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
#define FORK(i,a,b,c) for(int i=int(a);i<=int(b);i+=int(c))
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;

map<ll,pair<ll,multiset<ll> > >mp;
ll par[maxn],n,smc[maxn],cc[maxn],ifac[maxn],fac[maxn];

ll tavan(ll a,ll b){
    if(b==0)return 1;
    return ((b%2?a:1)*tavan((a*a)%mod,b/2))%mod;
}
inline ll C(ll N,ll K){
    if(N<K||K<0) return 0;
    return ((((fac[N]*ifac[K])%mod)*ifac[N-K])%mod);
}
ll calc(ll sma,multiset<ll>&s){
    ll nw=n+1-sz(s),smb=0;
    ll ans=(sma*((nw<3?0:smc[nw-3])+(nw<2?0:smc[nw-2])))%mod;
    for(ll x:s){
	sma-=x;
	//	cout<<smb*(C(n-2,nw-1)+C(n-2,nw))<<" "<<sma*(C(n-2,nw-2)+C(n-2,nw-1))<<" "<<x*C(n-1,nw)<<endl;
	ans=(ans-smb*(C(n-2,nw-1)+C(n-2,nw))+sma*(C(n-2,nw-2)+C(n-2,nw-1))-x*C(n-1,nw))%mod;
	smb+=x;
	nw++;
    }
    return ans;
}

int main(){
    fac[0]=1;
    FOR(i,1,maxn-1)
	fac[i]=(i*fac[i-1])%mod;
    ifac[maxn-1]=tavan(fac[maxn-1],mod-2);
    FORD(i,maxn-2,0)
	ifac[i]=((i+1)*ifac[i+1])%mod;
    FOR(i,2,maxn-1){
	if(par[i]==0){
	    FORK(j,i,maxn-1,i){
		par[j]=i;
	    }
	}
    }
    cin>>n;
    REP(i,maxn){
	smc[i]=((i==0?0:smc[i-1])+C(n-2,i))%mod;
    }
    REP(i,n){
	ll x;cin>>x;
	while(x>1){
	    ll p=par[x],cnt=0;
	    while(x%p==0){
		x/=p;
		cnt++;
	    }
	    mp[p].F+=cnt;
	    mp[p].S.insert(cnt);
	}
    }
    if(n==1){
	cout<<0;
	return 0;
    }
    ll ans=0;
    for(auto s:mp){
	ans=(ans+calc(s.S.F,s.S.S))%mod;
    }
    cout<<(ans+mod)%mod;
}