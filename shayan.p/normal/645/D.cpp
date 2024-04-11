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
const ll maxn=1e5+10;
const ll mod=1e9+7;

ll n,m;
vector<pll>v[maxn];
bool vis[maxn];
vector<ll>s;
map<pll,ll>mp;

void dfs(ll u,ll ind){
    vis[u]=1;
    REP(i,sz(v[u])){
	ll y=v[u][i].F;
	if(v[u][i].S>=ind)
	    continue;
	if(!vis[y])
	    dfs(y,ind);
    }
    s.PB(u);
}

bool ok(ll ind){
    memset(vis,0,sizeof vis);
    s.clear();
    FOR(i,1,n){
	if(!vis[i])
	    dfs(i,ind);
    }
    FORD(i,n-1,1){
	if(!mp.count(MP(s[i],s[i-1]))||mp[MP(s[i],s[i-1])]>=ind)
	    return 0;
    }
    return 1;
}

int main(){
    cin>>n>>m;
    REP(i,m){
	ll a,b;cin>>a>>b;
	v[a].PB(MP(b,i));
	mp[(MP(a,b))]=i;
    }
    ll l=1,r=m,ans=-1;
    while(l<=r){
	ll mid=(l+r)/2;
	if(ok(mid)){
	    ans=mid;
	    r=mid-1;
	}
	else{
	    l=mid+1;
	}
    }
    cout<<ans;
}