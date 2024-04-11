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

const ll maxn=210;
const ll Max=2e4+10;

ll n,a[maxn];
vector<ll>va,vb;
bool prim[Max];
vector<pll>v[maxn];
vector<vector<ll> >Ans;
vector<ll>vec;

bool vis[maxn];
ll par[maxn],mn[maxn];
pll f[maxn];

inline void edge(ll x,ll y){
    v[x].PB(MP(y+n,1));
    v[y+n].PB(MP(x,0));
}

void dfs(ll u){
    vis[u]=1;
    for(pll p:v[u]){
	if(!vis[p.F] && p.S){
	    par[p.F]=u;
	    mn[p.F]=min(mn[u],p.S);
	    dfs(p.F);
	}
    }
}

ll max_flow(ll s,ll t){
    ll ans=0;
    while(true){
	memset(vis,0,sizeof vis);
	memset(par,0,sizeof par);
	memset(mn,0,sizeof mn);
	mn[s]=10*n;
	dfs(s);
	if(mn[t]==0)
	    break;
	ll tmp=t,x=mn[t];
	ans+=x;
	while(tmp!=s){
	    REP(i,sz(v[tmp])){
		if(v[tmp][i].F==par[tmp])
		    v[tmp][i].S+=x;
	    }
	    REP(i,sz(v[par[tmp]])){
		if(v[par[tmp]][i].F==tmp)
		    v[par[tmp]][i].S-=x;
	    }
	    tmp=par[tmp];
	}
    }
    return ans;
}

int main(){
    prim[1]=1;
    FOR(i,2,Max-1){
	if(!prim[i]){
	    FORK(j,2*i,Max-1,i){
		prim[j]=1;
	    }
	}
    }
    cin>>n;
    FOR(i,1,n){
	cin>>a[i];
	if(a[i]%2)
	    va.PB(i);
	else
	    vb.PB(i);
    }
    if(sz(va)!=sz(vb)){
	cout<<"Impossible";
	return 0;
    }
    n=sz(va);
    FOR(i,1,n){
	FOR(j,1,n){
	    if(!prim[a[va[i-1]]+a[vb[j-1]]])
		edge(i,j);
	}
    }

    FOR(i,1,n){
	v[0].PB(MP(i,2));
	v[i].PB(MP(0,0));
    }
    FOR(i,n+1,2*n){
	v[i].PB(MP(2*n+1,2));
	v[2*n+1].PB(MP(i,0));
    }
    if(max_flow(0,2*n+1)!=(2*n)){
    	cout<<"Impossible";
	return 0;
    }
    FOR(i,1,2*n){
	for(pll p:v[i]){
	    if( (p.S==0 && i<=n) || (p.S==1 && i>n) ){
		if(f[i].F==0)
		    f[i].F=p.F;
		else
		    f[i].S=p.F;
	    }
	}
    }
    memset(vis,0,sizeof vis);
    FOR(i,1,2*n){
	if(!vis[i]){
	    vec.clear();
	    ll tmp=i,bef=-1;
	    while(!vis[tmp]){
		vis[tmp]=1;
		if(tmp>n)
		    vec.PB(vb[tmp-n-1]);
		else
		    vec.PB(va[tmp-1]);
		ll nxt;
		if(bef==f[tmp].F)
		    nxt=f[tmp].S;
		else
		    nxt=f[tmp].F;
		bef=tmp;
		tmp=nxt;
	    }
	    Ans.PB(vec);
	}
    }
    
    cout<<sz(Ans)<<endl;
    for(vector<ll>vv :Ans){
	cout<<sz(vv);
	for(ll x:vv)
	    cout<<" "<<x;
	cout<<endl;
    }
}