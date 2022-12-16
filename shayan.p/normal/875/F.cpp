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
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<pair<ll,pll> >vec;

ll par[maxn];
bool is[maxn];
ll Find(ll u){
    return (par[u]<0?u:(par[u]=Find(par[u])));
}

bool Merge(ll a,ll b){
    a=Find(a);b=Find(b);
    if(a==b){
	if(is[a])
	    return 0;
	is[a]=1;
	return 1;
    }
    if(is[a]&&is[b])return 0;
    if(par[a]>par[b])swap(a,b);
    par[a]+=par[b];
    par[b]=a;
    is[a]|=is[b];
    return 1;
}

int main(){
    fill(par,par+maxn,-1);
    ll n,m;cin>>n>>m;
    REP(i,m){
	ll a,b,x;cin>>a>>b>>x;
	vec.PB(MP(x,MP(a,b)));
    }
    sort(vec.begin(),vec.end(),greater<pair<ll,pll> >());
    
    ll ans=0;
    REP(i,m){
	if(Merge(vec[i].S.F,vec[i].S.S)){
	    ans+=vec[i].F;
	}
    }
    cout<<ans;
}