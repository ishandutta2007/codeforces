
// Wanna Hack? GL...

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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

bool mark[maxn];
vector<int>v[maxn];
vector<pii>qu[maxn];
int h[maxn],par[maxn],n;
int till[maxn];
ll ans[maxn];

void dfs(int u,int pr=-1){
    mark[u]=1;
    for(int y:v[u]){
	if(mark[y] && h[y]<h[u] && y!=pr){
	    int mn=y,mx=y,tmp=u;
	    while(tmp!=y){
		mn=min(mn,tmp);
		mx=max(mx,tmp);
		tmp=par[tmp];
	    }
	    till[mn]=mx-1;
	}
	if(!mark[y]){
	    h[y]=h[u]+1;
	    par[y]=u;
	    dfs(y,u);
	}
    }
}

ll val[4*maxn];
int lz[4*maxn];

void shift(int l,int r,int id=1){
    if(lz[id]==0) return;
    val[id]+=1ll*(r-l)*lz[id];
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void Add(int f,int s,int x,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) { lz[id]+=x;shift(l,r,id);return;}
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    val[id]=val[2*id]+val[2*id+1];
}
ll Ask(int f,int s,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return 0;
    shift(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	till[i]=n;
    }
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	if(!mark[i])
	    dfs(i);
    }
    for(int i=n-1;i>0;i--){
	till[i]=min(till[i+1],till[i]);
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
	int l,r;cin>>l>>r;
	qu[r].PB({l,i});
		   
    }
    int pos=1;
    for(int r=1;r<=n;r++){
	while(till[pos]<r) ++pos;
	Add(pos,r+1,1);
	for(pii p:qu[r])
	    ans[p.S]=Ask(p.F,r+1);
    }
    for(int i=0;i<q;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}