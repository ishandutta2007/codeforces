// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10;

vector<int>v[maxn],g[maxn];
vector<pair<int,pii> >sol;
int SZ[maxn],n;
set<pii>st;

void dfsSZ(int u,int par=-1){
    SZ[u]=1;
    for(int y:v[u]){
	if(y!=par){
	    dfsSZ(y,u);
	    SZ[u]+=SZ[y];
	}
    }
}

int dfsC(int u,int ss,int par=-1){
    for(int y:v[u]){
	if(y!=par && ss<SZ[y])
	    return dfsC(y,ss,u);
    }
    return u;
}

void pre(int u,int par){
    st.insert({u,par});
    for(int y:v[u])
	if(y!=par)
	    pre(y,u);
}

pii solve1(int u,int par){
    int pp=par,fr=-1;
    for(int y:v[u]){
	if(y!=par){
	    pii p=solve1(y,u);
	    sol.PB({pp,{u,p.S}});
	    st.erase({pp,u});
	    st.erase({u,pp});
	    st.insert({pp,p.S});
	    pp=p.F;
	    if(fr==-1) fr=p.S;
	}
    }
    if(fr==-1) return {u,u};
    return {fr,u};
}

int solve2(int u,int par){
    int rt=u;
    for(int y:g[u]){
	if(y!=par){
	    rt=solve2(y,u);
	    sol.PB({par,{u,rt}});
	}
    }
    return rt;
}

void dfs(int u,int par=-1){
    if(2*SZ[u]>=n){
	for(int y:v[u])
	    if(y!=par)
		dfs(y,u);
    }
    else{
	st.clear();
	pre(u,par);
	int rt=solve1(u,par).F;
	for(pii p:st)
	    g[p.F].clear(),g[p.S].clear();
	for(pii p:st)
	    g[p.F].PB(p.S),g[p.S].PB(p.F);
	solve2(rt,par);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfsSZ(1);
    int rt=dfsC(1,n/2);
    dfsSZ(rt);
    dfs(rt);
    cout<<sz(sol)<<"\n";
    for(auto x:sol)
	cout<<x.F<<" "<<x.S.F<<" "<<x.S.S<<"\n";
    return 0;
}