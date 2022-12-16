
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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int arr[maxn],a[maxn],sm,C,bef[maxn],aft[maxn],inid[maxn];
int ans[maxn];
vector<pii>vec[maxn];
vector< pair<int,pii> >vecq[maxn];// time // type // who
int N;

struct segment{
    int val[4*maxn],cnt[4*maxn],lz[4*maxn];
    void build(int l=0,int r=N,int id=1){
	val[id]=lz[id]=0,cnt[id]=r-l;
	if(r-l==1) return;
	int mid=(l+r)>>1;
	build(l,mid,2*id),build(mid,r,2*id+1);
    }
    void get(int l,int r,int id){
	val[id]=(1ll*val[id]+1ll*cnt[id]*lz[id])%mod;
	if(r-l>1){
	    lz[2*id]=(lz[2*id]+lz[id])%mod;
	    lz[2*id+1]=(lz[2*id+1]+lz[id])%mod;
	}
	lz[id]=0;
    }
    void on(int pos,int l=0,int r=N,int id=1){
	get(l,r,id);
	if(l>pos || pos>=r) return;
	cnt[id]++;
	if(r-l==1) { val[id]=0; return; }
	int mid=(l+r)>>1;
	on(pos,l,mid,2*id),on(pos,mid,r,2*id+1);
	val[id]=(val[2*id]+val[2*id+1])%mod;
    }
    void off(int pos,int l=0,int r=N,int id=1){
	get(l,r,id);
	if(l>pos || pos>=r) return;
	cnt[id]--;
	if(r-l==1) { val[id]=0; return; }
	int mid=(l+r)>>1;
	off(pos,l,mid,2*id),off(pos,mid,r,2*id+1);
	val[id]=(val[2*id]+val[2*id+1])%mod;
    }
    void add(int f,int s,int x,int l=0,int r=N,int id=1){
	if(f>=s || l>=r) return;
	get(l,r,id);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s) {lz[id]=x; get(l,r,id); return; }
	int mid=(l+r)>>1;
	add(f,s,x,l,mid,2*id);
	add(f,s,x,mid,r,2*id+1);
	val[id]=(val[2*id]+val[2*id+1])%mod;
    }
    int ask(int f,int s,int l=0,int r=N,int id=1){
	if(f>=s || l>=r) return 0;
	get(l,r,id);
	if(s<=l || r<=f) return 0;
	if(f<=l && r<=s) return val[id];
	int mid=(l+r)>>1;
	return (ask(f,s,l,mid,2*id)+ask(f,s,mid,r,2*id+1))%mod;
    }
}; segment seg,sega,segb;

void solve(vector<pii>&A,vector<pair<int,pii> >&B){
    if(sz(A)<3) return;
    int n=sz(A);
    set<int>st;
    N=n,sega.build(),segb.build();
    for(int i=0;i<n;i++){
	st.insert(i);
	sega.add(i,n,A[i].F);
	segb.add(0,i+1,A[i].S);
    }
    for(int i=2;i<n;i++){
	sm=(1ll*sm+1ll*A[i].S*sega.ask(0,i-1))%mod;
    }
    for(pair<int,pii> IT:B){
	int num=0,pos=IT.S.S;
	if(IT.S.F==1){// rem
	    auto it=st.lower_bound(pos);
	    int bef=-1,aft=-1;
	    if(it!=st.begin()) bef=*prev(it);
	    if(next(it)!=st.end()) aft=*next(it);
	    if(bef!=-1) num=(1ll*num-1ll*A[pos].S*sega.ask(0,bef))%mod;
	    if(aft!=-1)  num=(1ll*num-1ll*A[pos].F*segb.ask(aft+1,n))%mod;
	    if(bef!=-1 && aft!=-1)  num=(1ll*num -1ll*sega.ask(bef,bef+1)*segb.ask(aft,aft+1) )%mod;
	    sega.add(pos,n,-A[pos].F),segb.add(0,pos+1,-A[pos].S);
	    sega.off(pos),segb.off(pos),st.erase(pos);
	}
	else{// add
	    sega.on(pos),segb.on(pos),st.insert(pos);
	    auto it=st.lower_bound(pos);
	    int bef=-1,aft=-1;
	    if(it!=st.begin()) bef=*prev(it);
	    if(next(it)!=st.end()) aft=*next(it);

	    segb.add(0,pos+1,A[pos].S),sega.add(pos,n,A[pos].F);
	    sega.add(pos,pos+1, bef==-1 ? 0 : sega.ask(bef,bef+1) );
	    segb.add(pos,pos+1, aft==-1 ? 0 : segb.ask(aft,aft+1) );
	    
	    if(aft!=-1) num=(1ll*num+1ll*A[pos].F*segb.ask(aft+1,n))%mod;
	    if(bef!=-1) num=(1ll*num+1ll*A[pos].S*sega.ask(0,bef))%mod;
	    if(aft!=-1 && bef!=-1) num=(1ll*num + 1ll*sega.ask(bef,bef+1)*segb.ask(aft,aft+1) )%mod;
	}
	ans[IT.F]=num;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	arr[C++]=a[i];
    }
    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr;
    N=n,seg.build();
    for(int i=0;i<n;i++){
	a[i]=lower_bound(arr,arr+C,a[i])-arr;
	bef[i]=seg.ask(0,a[i]+1);
	inid[i]=seg.ask(a[i],a[i]+1);
	seg.add(a[i],a[i]+1,1);
    }
    seg.build();
    for(int i=n-1;i>=0;i--){
	aft[i]=seg.ask(0,a[i]+1);
	seg.add(a[i],a[i]+1,1);
    }
    for(int i=0;i<n;i++){
	vec[a[i]].PB({bef[i],aft[i]});
    }
    
    int q;cin>>q;
    for(int i=0;i<q;i++){
	int task,pos;cin>>task>>pos; --pos;
	vecq[a[pos]].PB({i,{task,inid[pos]}});
    }
    for(int i=0;i<C;i++){
	solve(vec[i],vecq[i]);
    }
    for(int i=0;i<q;i++){
	sm=(sm+ans[i])%mod;
	if(sm<0) sm+=mod;
	cout<<sm<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.