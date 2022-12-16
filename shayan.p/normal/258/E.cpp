// High above the clouds there is a rainbow...

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],g[maxn];

pii seg[maxn];
int C,n,ans[maxn];

int val[4*maxn],lz[4*maxn],cnt[4*maxn];

void build(int l=0,int r=n,int id=1){
    cnt[id]=r-l;
    if(r-l==1) return;
    int mid=(l+r)>>1;
    build(l,mid,2*id), build(mid,r,2*id+1);
}
void Merge(int id){
    val[id]=min(val[2*id],val[2*id+1]);
    cnt[id]=0;
    if(val[id]==val[2*id]) cnt[id]+=cnt[2*id];
    if(val[id]==val[2*id+1]) cnt[id]+=cnt[2*id+1];
}
void shift(int l,int r,int id=1){
    val[id]+=lz[id];
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) { lz[id]=x; shift(l,r,id); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
    Merge(id);
}

void dfs1(int u,int par=-1){
    seg[u].F=C++;
    for(int y:v[u]){
	if(y!=par)
	    dfs1(y,u);
    }
    seg[u].S=C;
}
void dfs2(int u,int par=-1){
    for(int y:g[u]){
	add(seg[y].F,seg[y].S,1);
    }
    if(val[1]==0) ans[u]=n-cnt[1];
    else ans[u]=n;
    for(int y:v[u]){
	if(y!=par){
	    dfs2(y,u);
	}
    }
    for(int y:g[u]){
	add(seg[y].F,seg[y].S,-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m;cin>>n>>m;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	g[a].PB(b);
	g[a].PB(a);
	g[b].PB(a);
	g[b].PB(b);
    }
    build();
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++){
	cout<<ans[i]-1+(ans[i]==0)<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.