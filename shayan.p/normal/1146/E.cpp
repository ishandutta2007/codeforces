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

const int maxn=1e5+10,mod=998244353;

int a[maxn],id[maxn],n;
pii seg[maxn];

bool val[4*maxn];
int lz[4*maxn];

void build(int l=0,int r=n,int i=1){
    if(r-l==1){
	val[i]=(a[id[l]]<0 ? 1 : 0);
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*i);
    build(mid,r,2*i+1);
}

// -1 1 2 : rev put 0 put 1

void get(int l,int r,int id){
    if(lz[id]==0) return;
    if(r-l==1){
	if(lz[id]==-1) val[id]^=1;
	if(lz[id]==1) val[id]=0;
	if(lz[id]==2) val[id]=1;
    }
    else{
	if(lz[id]==1) lz[2*id]=lz[2*id+1]=1;
	else if(lz[id]==2) lz[2*id]=lz[2*id+1]=2;
	else{
	    if(lz[2*id]==0) lz[2*id]=-1;
	    else if(lz[2*id]==-1) lz[2*id]=0;
	    else if(lz[2*id]==1) lz[2*id]=2;
	    else if(lz[2*id]==2) lz[2*id]=1;

	    if(lz[2*id+1]==0) lz[2*id+1]=-1;
	    else if(lz[2*id+1]==-1) lz[2*id+1]=0;
	    else if(lz[2*id+1]==1) lz[2*id+1]=2;
	    else if(lz[2*id+1]==2) lz[2*id+1]=1;
	}
    }
    lz[id]=0;
}

void rev(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]=-1; return;}
    int mid=(l+r)>>1;
    rev(f,s,l,mid,2*id);
    rev(f,s,mid,r,2*id+1);
}
void frc(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]=x+1; return;}
    int mid=(l+r)>>1;
    frc(f,s,x,l,mid,2*id);
    frc(f,s,x,mid,r,2*id+1);
}
bool ask(int pos,int l=0,int r=n,int id=1){
    get(l,r,id);
    if(r-l==1) return val[id];
    int mid=(l+r)>>1;
    if(pos<mid) return ask(pos,l,mid,2*id);
    return ask(pos,mid,r,2*id+1);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>n>>q;
    for(int i=0;i<n;i++){
	cin>>a[i];
	id[i]=i;
    }
    sort(id,id+n,[](int x,int y){return abs(a[x])<=abs(a[y]);});
    int pt=0;
    for(int i=0;i<maxn;i++){
	seg[i].F=pt;
	while(pt<n && abs(a[id[pt]])==i) ++pt;
	seg[i].S=pt;
    }
    build();
    while(q--){
	char ch; int x; cin>>ch>>x;
	bool any=0,bl=ch=='<';
	if(x<0){ any=1,bl=bl^1,x*=-1,rev(0,n); }
	if(bl){
	    frc(seg[x].F,n,0);
	    rev(0,seg[x].F);
	}
	else{
	    frc(seg[x].S,n,1);
	}
	if(any) rev(0,n);
    }
    for(int i=0;i<n;i++){
	bool b=ask(i);
	a[id[i]]=abs(a[id[i]]) * (b ? -1 : 1);
    }
    for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.