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
typedef long double ld;

const int maxn=2e5+10,inf=1e7;

vector<int>pos[maxn];
vector<int>dv[maxn];
int n,mn[4*maxn],mn2[4*maxn],lz[4*maxn],cnt[4*maxn];
ll vl[4*maxn];

void get(int l,int r,int id){
    if(mn[id]>=lz[id]){
	lz[id]=-1;
	return;
    }
    vl[id]+=1ll*(lz[id]-mn[id])*cnt[id];
    mn[id]=lz[id];
    if(r-l>1){
	lz[2*id]=max(lz[2*id],lz[id]);
	lz[2*id+1]=max(lz[2*id+1],lz[id]);
    }
    lz[id]=-1;
}
void upd(int id){
    mn[id]=min(mn[2*id],mn[2*id+1]),cnt[id]=0;
    vl[id]=vl[2*id]+vl[2*id+1];
    if(mn[id]==mn[2*id]) cnt[id]+=cnt[2*id];
    if(mn[id]==mn[2*id+1]) cnt[id]+=cnt[2*id+1];
    mn2[id]=min(mn2[2*id],mn2[2*id+1]);
    if(mn[id]!=mn[2*id]) mn2[id]=min(mn2[id],mn[2*id]);
    if(mn[id]!=mn[2*id+1]) mn2[id]=min(mn2[id],mn[2*id+1]);
}
void Add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f || x<=mn[id]) return;
    if(f<=l && r<=s && mn2[id]>x) {lz[id]=x,get(l,r,id);return;}
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    upd(id);
}
void build(int l=0,int r=n,int id=1){
    lz[id]=-1;
    if(r-l==1){
	vl[id]=l,mn[id]=l,mn2[id]=inf,cnt[id]=1;
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    upd(id);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=1;i<maxn;i++){
	for(int j=i;j<maxn;j+=i)
	    dv[j].PB(i);
    }
    cin>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	for(int y:dv[x]){
	    pos[y].PB(i);
	}
    }
    build();
    ll ans=0;
    for(int i=maxn-1;i>0;i--){
	if(sz(pos[i])>1){
	    Add(pos[i][1]+1,n,n);
	    Add(pos[i][0]+1,pos[i][1]+1,pos[i].back());
	    Add(0,pos[i][0]+1,pos[i][sz(pos[i])-2]);
	}
	ll bad=1ll*n*n-vl[1];
	ans+=((1ll*n*(n+1))/2)-bad;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.