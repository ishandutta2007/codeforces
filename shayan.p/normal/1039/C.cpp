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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=5e5+10;
const ll mod=1e9+7;

ll c[maxn],n,m,k;
map<ll,vector<pll> >mp;
vector<ll>vec;
ll par[maxn];

ll Find(ll u){
    if(par[u]<0)return u;
    return (par[u]=Find(par[u]));
}
bool Merge(ll a,ll b){
    if((a=Find(a)) == (b=Find(b)) )return 0;
    if(par[a]>par[b])swap(a,b);
    par[a]+=par[b];
    par[b]=a;
    vec.PB(a);
    vec.PB(b);
    return 1;
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

ll solve(vector<pll>&v){
    for(ll x:vec)
	par[x]=-1;
    vec.clear();
    ll comp=n;
    for(pll p:v){
	if(Merge(p.F,p.S))
	    comp--;
    }
    return tavan(2,comp);
}

int main(){
    memset(par,-1,sizeof par);
    
    scanf("%lld%lld%lld",&n,&m,&k);
    FOR(i,1,n){
	scanf("%lld",&c[i]);
    }
    FOR(i,1,m){
	ll x,y;scanf("%lld%lld",&x,&y);
	mp[c[x]^c[y]].PB({x,y});
    }
    ll ans=0;
    for(auto pp:mp){
	ans=(ans+solve(pp.S))%mod;
    }
    ans=(ans+((tavan(2,k)-ll(sz(mp)))*tavan(2,n)))%mod;
    printf("%lld",ans);
}