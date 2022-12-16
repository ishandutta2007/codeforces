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

const int maxn=1010,Big=1e9+10;

int x[maxn],y[maxn],arr[maxn],C;
map<int,vector<pair<bool,pii> > > mp;

int N,posf[4*maxn],poss[4*maxn],lz[4*maxn],val[4*maxn];

void build(int l=0,int r=N,int id=1){
    posf[id]=l,poss[id]=r-1,lz[id]=0,val[id]=0;
    if(r-l==1) return;
    int mid=(l+r)>>1;
    build(l,mid,2*id), build(mid,r,2*id+1);
}
void shift(int l,int r,int id){
    val[id]+=lz[id];
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void Merge(int id){
    val[id]=min(val[2*id],val[2*id+1]);
    posf[id]=Big,poss[id]=-Big;
    if(val[2*id]==val[id]) posf[id]=min(posf[id],posf[2*id]), poss[id]=max(poss[id],poss[2*id]);
    if(val[2*id+1]==val[id]) posf[id]=min(posf[id],posf[2*id+1]), poss[id]=max(poss[id],poss[2*id+1]);
}
void add(int f,int s,int x,int l=0,int r=N,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]=x; shift(l,r,id); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
    Merge(id);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<k;i++){
	cin>>x[i]>>y[i];
	--x[i],--y[i];
    }
    int l=-1,r=Big;
    while(r-l>1){
	mp.clear(),C=0;
	int mid=(l+r)>>1;
	for(int i=0;i<k;i++){
	    int h=x[i]-mid,A=y[i]-mid,B=y[i]+mid+1;
	    h=max(h,0),A=max(A,0),B=min(B,m);
	    mp[h].PB({1,{A,B}});

	    h=x[i]+mid+1, h=min(h,n);
	    mp[h].PB({0,{A,B}});

	    arr[C++]=A, arr[C++]=B;
	}
	int U=-1,D=m,L=n,R=-1;
	if((mp.begin()->F) >0) L=0,U=m-1,D=0;
	if((mp.rbegin()->F) < n) R=n-1,U=m-1,D=0;
	L=min(L,(mp.rbegin()->F));
	R=max(R,(mp.begin()->F)-1);
	
	arr[C++]=m,arr[C++]=0;
	sort(arr,arr+C);
	C=unique(arr,arr+C)-arr;

	N=C-1;
	build();
	
	for(auto &it:mp){
	    for(auto x:it.S){
		add( lower_bound(arr,arr+C,x.S.F)-arr, lower_bound(arr,arr+C,x.S.S)-arr, x.F==0 ? -1 : 1 );
	    }
	    if(val[1]!=0 || it.F==n) continue;
	    L=min(L,it.F), R=max(R,it.F);
	    D=min(D,arr[posf[1]]), U=max(U,arr[poss[1]+1]-1);
	}
	if(U-D <= 2*mid && R-L <= 2*mid) r=mid;
	else l=mid;
    }
    return cout<<r<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.