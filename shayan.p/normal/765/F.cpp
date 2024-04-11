// Faster!

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

const int maxn=3e5+10,inf=1e9+100;

vector<pii>qu[maxn];
int ans[maxn],a[maxn],lz[4*maxn],n;
vector<int>v[maxn];

void build(int l=0,int r=n,int id=1){
    v[id].clear();
    lz[id]=inf;
    if(r-l==1){
	v[id].PB(a[l]);
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    v[id].resize(sz(v[2*id])+sz(v[2*id+1]));
    merge(v[2*id].begin(),v[2*id].end(),v[2*id+1].begin(),v[2*id+1].end(),v[id].begin());
}
bool pre(int id,int vf,int vs){
    int num=lower_bound(v[id].begin(),v[id].end(),vf)-v[id].begin();
    if(num==sz(v[id])) return 0;
    return v[id][num]<=vs;
}
int go(int l,int r,int id,int vf,int vs){
    if(r-l==1) return l;
    int mid=(l+r)>>1;
    if(pre(2*id+1,vf,vs)) return go(mid,r,2*id+1,vf,vs);
    return go(l,mid,2*id,vf,vs);
}
pair<pii,int> fndid(int f,int s,int vf,int vs,int l=0,int r=n,int id=1){
    if(f>=s || l>=r || r<=f || s<=l) return {{-1,-1},-1};
    int mid=(l+r)>>1;
    if(f<=l && r<=s) return (pre(id,vf,vs)==0 ? (pair<pii,int>){{-1,-1},-1} : (pair<pii,int>) {{l,r},id} );
    auto num=fndid(f,s,vf,vs,mid,r,2*id+1);
    if(num.S!=-1) return num;
    return fndid(f,s,vf,vs,l,mid,2*id);
}
int fnd(int f,int s,int vf,int vs){
    auto num=fndid(f,s,vf,vs);
    if(num.S==-1) return -1;
    return go(num.F.F,num.F.S,num.S,vf,vs);
}

void get(int l,int r,int id){
    if(r-l>1){
	lz[2*id]=min(lz[2*id],lz[id]);
	lz[2*id+1]=min(lz[2*id+1],lz[id]);
    }
}
void add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) { lz[id]=min(lz[id],x); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
}
int ask(int pos,int l=0,int r=n,int id=1){
    if(r-l==1) return lz[id];
    get(l,r,id);
    int mid=(l+r)>>1;
    if(pos<mid) return ask(pos,l,mid,2*id);
    return ask(pos,mid,r,2*id+1);
}

void solve(){
    build();
    for(int i=0;i<n;i++){
	int befv=inf,befi=i;
	while(true){
	    int num=fnd(0,befi,a[i],befv);
	    if(num==-1 || a[num]<a[i]) break;
	    add(0,num+1,a[num]-a[i]);
	    if(befv==a[i]) break;
	    befi=num,befv=(befv+a[i])/2;
	}
	for(pii p:qu[i]){
	    ans[p.S]=min(ans[p.S],ask(p.F));
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int q;cin>>q;
    fill(ans,ans+q,inf);
    for(int i=0;i<q;i++){
	int l,r;cin>>l>>r;
	qu[--r].PB({--l,i});
    }
    solve();
    for(int i=0;i<n;i++){
	a[i]=(1e9)-a[i];
    }
    solve();
    for(int i=0;i<q;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.