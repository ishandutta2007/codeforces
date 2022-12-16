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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=5010;
const ll inf=4e9+10;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")

ll n,m;
vector<ll>gr[maxn],rv[maxn];
bool vis[maxn];
ll scc[maxn];
vector<ll>vcc[maxn];
stack<ll>st;
ll cn;


void dfs_rv(ll u){
    vis[u]=1;
    scc[u]=cn;
    vcc[cn].PB(u);
    REP(i,ll(sz(rv[u]))){
	if(!vis[rv[u][i]]){
	    dfs_rv(rv[u][i]);
	}
    }
}

void dfs_gr(ll u){
    vis[u]=1;
    REP(i,ll(sz(gr[u]))){
	if(!vis[gr[u][i]]){
	    dfs_gr(gr[u][i]);
	}
    }
    st.push(u);
}

void SCC(){
    FOR(i,1,n){
	if(!vis[i]){
	    dfs_gr(i);
	}
    }
    memset(vis,0,sizeof vis);
    while(sz(st)){
	if(!vis[st.top()]){
	    dfs_rv(st.top());
	    cn++;
	}
	st.pop();
    }
}

ll hn[maxn],hp[maxn];
stack<ll>sn,sp;
void Clear(){
    while(sz(sn)){
	hn[sn.top()]=0;
	sn.pop();
    }
    while(sz(sp)){
	hp[sp.top()]=0;
	sp.pop();
    }
}
void addp(ll ind,ll x){
    hp[ind]=x;
    sp.push(ind);
}
void addn(ll ind,ll x){
    hn[ind]=x;
    sn.push(ind);
}

ll ask(ll c){
    ll ans=inf;
    queue<ll>q;
    vector<pll>ed;
    vector<ll>&v=vcc[c];
    REP(i,ll(sz(v))){
	Clear();
	ed.clear();
	addp(v[i],1);
	addn(v[i],1);
	
	q.push(v[i]);
	while(sz(q)){
	    ll t=q.front();
	    q.pop();
	    REP(j,ll(sz(gr[t]))){
		ll y=gr[t][j];
		if(scc[y]==c){
		    ed.PB(MP(t,y));
		    if(!hp[y]){
			addp(y,hp[t]+1);
			q.push(y);
		    }
		}
	    }
	}
	
	q.push(v[i]);
	while(sz(q)){
	    ll t=q.front();
	    q.pop();
	    REP(j,ll(sz(rv[t]))){
		ll y=rv[t][j];
		if(scc[y]==c){
		    if(!hn[y]){
			addn(y,hn[t]+1);
			q.push(y);
		    }
		}
	    }
	}

	REP(j,ll(sz(ed))){
	    ans=min(ans,hp[ed[j].F]+hn[ed[j].S]-1);
	}
    }
    return ans;
}

bool isn[maxn];
pll p[maxn];

int main(){
    cin>>n>>m;
    REP(i,m){
	cin>>p[i].F>>p[i].S;
	gr[p[i].F].PB(p[i].S);
	rv[p[i].S].PB(p[i].F);
    }
    SCC();
    REP(i,m){
	if(scc[p[i].F]!=scc[p[i].S]){
	    isn[scc[p[i].F]]=1;
	}
    }
    ll ans=n;
    REP(i,cn){
	if(!isn[i]){
	    if(sz(vcc[i])!=1){
		ans+=998*ask(i)+1;
	    }
	}	    
    }
    cout<<ans;
}