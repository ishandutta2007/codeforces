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

const int maxn=6e5+10,mod=1e9+7;

int arr[maxn],C;

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1)
	    ans=1ll*ans*a %mod;
    }
    return ans;
}

struct Segment{
    int val[4*maxn],L[4*maxn],R[4*maxn],lz[4*maxn],Tw[4*maxn];
    Segment(){
	memset(val,0,sizeof val);
	memset(lz,-1,sizeof lz);
    }
    void build(int l=0,int r=C,int id=1){
	if(r-l==1){
	    Tw[id]=Pow(2,arr[r]-arr[l]);
	    R[id]=arr[r],L[id]=arr[l];
	    return;
	}
	int mid=(l+r)>>1;
	build(l,mid,2*id);
	build(mid,r,2*id+1);
	Tw[id]=1ll*Tw[2*id]*Tw[2*id+1] %mod;
	R[id]=R[2*id+1],L[id]=L[2*id];
    }
    void get(int l,int r,int id=1){
	if(lz[id]==-1) return;
	val[id]=1ll*(Tw[id]-1+mod)*lz[id] %mod;
	if(r-l>1){
	    lz[2*id]=lz[id];
	    lz[2*id+1]=1ll*lz[id]*Tw[2*id] %mod;
	}
	lz[id]=-1;
    }
    int Add(int f,int s,int x,int l=0,int r=C,int id=1){
	if(x<0) x+=mod;
	if(l>=r || f>=s) return 1;
	get(l,r,id);
	if(s<=L[id] || R[id]<=f) return 1;
	if(f<=L[id] && R[id]<=s) {lz[id]=x; get(l,r,id); return Tw[id]; }
	int mid=(l+r)>>1;
	int A=Add(f,s,x,l,mid,2*id);
	int B=Add(f,s,1ll*x*A %mod,mid,r,2*id+1) %mod;
	val[id]=(val[2*id]+val[2*id+1])%mod;
	return 1ll*A*B %mod;
    }
    int Ask(int f,int s,int l=0,int r=C,int id=1){
	if(l>=r || f>=s) return 0;
	get(l,r,id);
	if(s<=L[id] || R[id]<=f) return 0;
	if(f<=L[id] && R[id]<=s) return val[id];
	int mid=(l+r)>>1;
	return (Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1))%mod;
    }
};Segment seg[2];

map<int,vector<pair<int,bool> > >mp;
int MX[2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int N,n,m;cin>>N>>n>>m;
    while(n--){
	int a,b;cin>>a>>b;
	mp[b].PB({a,0});
	arr[C++]=b;
	arr[C++]=b+1;
	arr[C++]=a;
    }
    while(m--){
	int a,b;cin>>a>>b;
	mp[b].PB({a,1});
	arr[C++]=b;
	arr[C++]=b+1;
	arr[C++]=a;
    }
    mp[N+1].PB({-1,0});
    arr[C++]=N+1;
    arr[C++]=N;
    arr[C++]=0;
    arr[C++]=1;
    arr[C++]=2;

    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr-1;

    seg[0].build(),seg[1].build();
    seg[0].Add(0,1,1),seg[1].Add(0,1,1);
    
    int pos=1,DP0=1,DP1=1;
    for(auto &IT:mp){
	seg[0].Add(pos,pos+1,DP0);
	seg[1].Add(pos,pos+1,DP1);
	seg[0].Add(pos+1,IT.F,(DP0+DP1)%mod);
	seg[1].Add(pos+1,IT.F,(DP0+DP1)%mod);
	pos=IT.F;
	for(auto p:IT.S){
	    if(p.S) MX[0]=max(MX[0],p.F);
	    else    MX[1]=max(MX[1],p.F);
	}
	DP0=seg[1].Ask(MX[0],IT.F);
	DP1=seg[0].Ask(MX[1],IT.F);
    }
    return cout<<(seg[0].Ask(N,N+1)+seg[1].Ask(N,N+1))%mod<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.