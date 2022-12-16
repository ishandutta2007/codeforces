// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int val[4*maxn];
bool lz[4*maxn];
void get(int l,int r,int id){
    if(!lz[id]) return;
    val[id]=r-l-val[id];
    if(r-l>1){
	lz[2*id]^=1;
	lz[2*id+1]^=1;
    }
    lz[id]=0;
}
void Add(int f,int s,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) {lz[id]^=1,get(l,r,id);return;}
    int mid=(l+r)>>1;
    Add(f,s,l,mid,2*id);
    Add(f,s,mid,r,2*id+1);
    val[id]=val[2*id]+val[2*id+1];
}
int Ask(int f,int s,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return 0;
    get(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1);
}

vector<int>v[maxn],g[maxn],cyc;
int col[maxn],SZ[maxn],par[maxn],h[maxn],st[maxn],C;
bool mark[maxn];

bool cycle(int u,int pr=0){
    for(int y:v[u]){
	if(par[y]>0 && y!=pr){
	    int tmp=u;
	    while(tmp!=y){
		cyc.PB(tmp);
		tmp=par[tmp];
	    }
	    cyc.PB(y);
	    return 1;
	}
	if(par[y]==0){
	    par[y]=u;
	    if(cycle(y,u))
		return 1;
	}
    }
    return 0;
}
int dfssz(int u,int cl,int pr=0){
    if(pr!=0) g[pr].PB(u),g[u].PB(pr);
    SZ[u]=1;col[u]=cl;
    for(int y:v[u]){
	if(!mark[y] && y!=pr){
	    SZ[u]+=dfssz(y,cl,u);
	}
    }
    return SZ[u];
}
void prep(int u,bool is=0,int pr=0){
    sort(g[u].begin(),g[u].end(),[](int a,int b){return SZ[a]<SZ[b];;});
    if(pr==0) g[u].PB(0);
    par[u]=(is?par[pr]:u); h[u]=h[pr]+1; st[u]=C++;
    if(sz(g[u])>1)
	prep(g[u][sz(g[u])-2],1,u);
    for(int i=0;i<sz(g[u])-2;i++)
	prep(g[u][i],0,u);
}
void handle(int a,int b){
    while(par[a]!=par[b]){
	if(h[par[a]]<h[par[b]]) swap(a,b);
	Add(st[par[a]],st[a]+1);
	a=g[par[a]].back();
    }
    if(h[a]<h[b]) swap(a,b);
    Add(st[b]+1,st[a]+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    par[1]=1;
    cycle(1);
    for(int x:cyc){
	mark[x]=1;
    }
    for(int i=0;i<sz(cyc);i++){
	dfssz(cyc[i],i);
	prep(cyc[i]);
    }
    while(q--){
	int a,b;cin>>a>>b;
	if(col[a]==col[b]){
	    handle(a,b);
	}
	else{
	    handle(a,cyc[col[a]]),a=col[a];
	    handle(b,cyc[col[b]]),b=col[b];
	    int A=(b-a+sz(cyc))%sz(cyc),B=(a-b+sz(cyc))%sz(cyc),L=-1,R=-1;
	    if(A<B || (A==B && cyc[(a+1)%sz(cyc)]<cyc[(a+sz(cyc)-1)%sz(cyc)]))
		L=a,R=b;
	    else
		L=b,R=a;
	    if(L>R) Add(L+n,sz(cyc)+n),L=0;
	    Add(L+n,R+n);
	}
	cout<<n-Ask(0,n+sz(cyc))+(Ask(n,n+sz(cyc))==sz(cyc))<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.