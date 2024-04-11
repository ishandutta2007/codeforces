// Jump, and you will find out how to unfold your wings as you fall.

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define tm sth_really_strange

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pll> pi3;
typedef pair<pll,pll> pl4;

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

ll W[maxn];
pl4 val[4*maxn],vv[maxn];
vector<pi3> v[maxn];
int h[maxn],tp[maxn],tm[maxn],SZ[maxn],who[maxn],C;
bool mark[maxn];

int prep(int u,int par=0){
    SZ[u]=1;
    for(auto p:v[u]){
	if(p.F!=par)
	    SZ[u]+=prep(p.F,u);
    }
    return SZ[u];
}

void dfs(int u,int par=0,bool is=1,ll W1=0,ll W2=0){
    vv[u].F.F = min( W1, W[par]+W[u]+W2);
    vv[u].S.S = min( W2, W[par]+W[u]+W1);
    vv[u].F.S = min( W1+W[par] , W[u]+W2);
    vv[u].S.F = min( W2+W[par] , W[u]+W1);
    tm[u]=++C;
    who[C]=u;
    h[u]=h[par]+1;
    if(is) tp[u]=u;
    else tp[u]=tp[par];
    sort(v[u].begin(),v[u].end(),[](pi3 a,pi3 b){ return SZ[a.F]<SZ[b.F]; } );
    if(par==0) v[u].PB({0,{-1,-1}});
    if(sz(v[u])>1)
	dfs(v[u][sz(v[u])-2].F,u,0,v[u][sz(v[u])-2].S.F,v[u][sz(v[u])-2].S.S);
    for(int i=0;i<sz(v[u])-2;i++)
	dfs(v[u][i].F,u,1,v[u][i].S.F,v[u][i].S.S);
}

pl4 operator + (pl4 a,pl4 b){
    pl4 c;
    c.F.F=min( a.F.F+b.F.F, a.F.S+b.S.F );
    c.F.S=min( a.F.S+b.S.S, a.F.F+b.F.S );
    c.S.F=min( a.S.F+b.F.F , a.S.S+b.S.F);
    c.S.S=min( a.S.S+b.S.S , a.S.F+b.F.S);
    return c;
}

void build(int l=0,int r=C,int id=1){
    if(r-l==1){
	val[id]=vv[who[r]];
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    val[id]=val[2*id+1]+val[2*id];
}

pl4 Ask(int f,int s,int l=0,int r=C,int id=1){
    if(f>=s || l>=r || s<=l || r<=f) return {{0,inf},{inf,0}};
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return Ask(f,s,mid,r,2*id+1)+Ask(f,s,l,mid,2*id);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>W[i];
    }
    for(int i=1;i<=n-1;i++){
	int a,b;cin>>a>>b;
	ll A,B;cin>>A>>B;
	v[a].PB({b,{A,B}});
	v[b].PB({a,{A,B}});
    }
    priority_queue<pll,vector<pll>,greater<pll> >pq;
    for(int i=1;i<=n;i++){
	pq.push({W[i],i});
    }
    while(sz(pq)){
	int u=pq.top().S;
	pq.pop();
	if(mark[u]) continue;
	mark[u]=1;
	for(pi3 p:v[u]){
	    if(W[p.F]>W[u]+p.S.F+p.S.S)
		W[p.F]=W[u]+p.S.F+p.S.S,pq.push({W[p.F],p.F});
	}
    }
    prep(1);
    dfs(1);
    build();
    int q;cin>>q;
    while(q--){
	int A,B;cin>>A>>B;
	bool a=1-(A&1),b=1-(B&1);
	A=(A+1)>>1,B=(B+1)>>1;
	pl4 wa={{0,W[A]},{W[A],0}},wb={{0,W[B]},{W[B],0}};
	while(tp[A]!=tp[B]){
	    if(h[tp[A]]<h[tp[B]]) swap(A,B),swap(wa,wb),swap(a,b);
	    wa=wa+Ask(tm[tp[A]]-1,tm[A]);
	    A=v[tp[A]].back().F;
	}
	if(h[A]<h[B]) swap(A,B),swap(wa,wb),swap(a,b);
	wa=wa+Ask(tm[B],tm[A]);
	swap(wb.F.S,wb.S.F);
	wa=wa+wb;
	ll ans=inf;
	if(a==0 && b==0) ans=wa.F.F;
	if(a==0 && b==1) ans=wa.F.S;
	if(a==1 && b==0) ans=wa.S.F;
	if(a==1 && b==1) ans=wa.S.S;
	cout<<ans<<"\n";
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.