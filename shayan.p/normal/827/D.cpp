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

const int maxn=2e5+10,inf=2e9;

int w[maxn],h[maxn],ans[maxn],par[maxn];
pair<pii,pii>p[maxn];
vector<pii> v[maxn];
int sp[20][maxn],spw[20][maxn];
vector<int>ad[maxn],dl[maxn];
set<int> inmst;
map<int,int>mp[maxn];

int Find(int u){
    if(par[u]<0) return u;
    return par[u]=Find(par[u]);
}

void Merge(int a,int b,int c){
    int A=Find(a),B=Find(b);
    if(A==B) return;
    v[a].PB({b,c});
    v[b].PB({a,c});
    a=A;b=B;
    if(par[a]>par[b]) swap(a,b);
    inmst.insert(c);
    par[a]+=par[b];
    par[b]=a;
}

void dfs1(int u,int H=1,int par=0,int id=0){
    h[u]=H;
    spw[0][u]=w[id];
    sp[0][u]=par;
    for(int i=1;i<20;i++){
	sp[i][u]=sp[i-1][sp[i-1][u]];
	spw[i][u]=max(spw[i-1][u],spw[i-1][sp[i-1][u]]);
    }
    for(pii p:v[u]){
	if(p.F!=par)
	    dfs1(p.F,H+1,u,p.S);
    }
}

void dfs2(int u,int par=0){
    for(pii p:v[u]){
	if(p.F!=par){
	    dfs2(p.F,u);
	    if(!mp[p.F].empty()){
		ans[p.S]=(mp[p.F].begin()->F)-1;
		if(sz(mp[p.F])>sz(mp[u])) swap(mp[u],mp[p.F]);
		for(pii pp:mp[p.F])
		    mp[u][pp.F]+=pp.S;
	    }
	    mp[p.F].clear();
	}
    }
    for(int x:ad[u]){
	mp[u][x]++;
    }
    for(int x:dl[u]){
	if((mp[u][x]=mp[u][x]-2)==0)
	    mp[u].erase(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fill(par,par+maxn,-1);
    fill(ans,ans+maxn,inf);
    
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
	cin>>p[i].S.F>>p[i].S.S>>w[i],p[i].F={w[i],i};
    sort(p,p+m);
    for(int i=0;i<m;i++)
	Merge(p[i].S.F,p[i].S.S,p[i].F.S);
    dfs1(1);
    for(int i=0;i<m;i++){
	if(!inmst.count(p[i].F.S)){
	    int A=p[i].S.F,B=p[i].S.S,lc,mx=0;
	    ad[A].PB(p[i].F.F);
	    ad[B].PB(p[i].F.F);
	    if(h[A]<h[B]) swap(A,B);
	    for(int i=19;i>=0;i--){
		if(h[sp[i][A]]>=h[B]){
		    mx=max(mx,spw[i][A]);
		    A=sp[i][A];
		}
	    }
	    if(A==B){
		lc=A;
	    }
	    else{
		for(int i=19;i>=0;i--){
		    if(sp[i][A]!=sp[i][B]){
			mx=max(mx,max(spw[i][A],spw[i][B]));
			A=sp[i][A];
			B=sp[i][B];
		    }
		}
		mx=max(mx,max(spw[0][A],spw[0][B]));
		lc=A=B=sp[0][A];
	    }
	    ans[p[i].F.S]=mx-1;
	    dl[lc].PB(p[i].F.F);
	}
    }
    dfs2(1);
    for(int i=0;i<m;i++){
	if(ans[i]==inf) ans[i]=-1;
	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}