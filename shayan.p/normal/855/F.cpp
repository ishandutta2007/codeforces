// Phoenix

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

const int maxn=1e5+10,inf=1e9+10;

struct SMin{
    int val[4*maxn],lz[4*maxn];
    SMin(){
	fill(val,val+4*maxn,inf);
	fill(lz,lz+4*maxn,inf);
    }
    void get(int l,int r,int ind){
	val[ind]=min(val[ind],lz[ind]);
	if(r-l>1){
	    lz[2*ind]=min(lz[2*ind],lz[ind]);
	    lz[2*ind+1]=min(lz[2*ind+1],lz[ind]);
	}
	lz[ind]=inf;
    }
    void add(int f,int s,int x,int l=0,int r=maxn,int ind=1){// [)
	if(f>=s || l>=r) return;
	get(l,r,ind);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s){
	    lz[ind]=x;
	    get(l,r,ind);
	    return;
	}
	int mid=(l+r)>>1;
	add(f,s,x,l,mid,2*ind);
	add(f,s,x,mid,r,2*ind+1);
	val[ind]=min(val[2*ind],val[2*ind+1]);
    }
    void Set(int pos,int x,int l=0,int r=maxn,int ind=1){
	if(l>=r) return;
	get(l,r,ind);
	if(r-l==1){
	    val[ind]=x;
	    return;
	}
	int mid=(l+r)>>1;
	if(pos<mid) Set(pos,x,l,mid,2*ind);
	else Set(pos,x,mid,r,2*ind+1);
	val[ind]=min(val[2*ind],val[2*ind+1]);
    }
    int ask(int pos,int l=0,int r=maxn,int ind=1){
	if(l>=r) return inf;
	get(l,r,ind);
	if(r-l==1) return val[ind];
	int mid=(l+r)>>1;
	if(pos<mid) return ask(pos,l,mid,2*ind);
	return ask(pos,mid,r,2*ind+1);
    }
};

struct SBeats{
    int cnt[4*maxn],MX[4*maxn],SMX[4*maxn],lz[4*maxn];
    ll sm[4*maxn];
    void Merge(int ind){
	MX[ind]=max(MX[2*ind],MX[2*ind+1]);
	SMX[ind]=-inf;
	cnt[ind]=0;
	if(MX[ind]==MX[2*ind]) cnt[ind]+=cnt[2*ind],SMX[ind]=max(SMX[ind],SMX[2*ind]);
	else SMX[ind]=max(SMX[ind],MX[2*ind]);
	if(MX[ind]==MX[2*ind+1]) cnt[ind]+=cnt[2*ind+1],SMX[ind]=max(SMX[ind],SMX[2*ind+1]);
	else SMX[ind]=max(SMX[ind],MX[2*ind+1]);
	sm[ind]=sm[2*ind]+sm[2*ind+1];
    }
    void build(int l=0,int r=maxn,int ind=1){// aval hame 0 hastan
	if(r-l==1){
	    cnt[ind]=1;
	    SMX[ind]=-inf;
	    lz[ind]=inf;
	    return;
	}
	int mid=(l+r)>>1;
	build(l,mid,2*ind);
	build(mid,r,2*ind+1);
	Merge(ind);
	lz[ind]=inf;
    }
    SBeats(){
	build();
    }
    void get(int l,int r,int ind){
	if(lz[ind]>=MX[ind]) return;
	sm[ind]+=1ll*(lz[ind]-MX[ind])*cnt[ind];
	MX[ind]=lz[ind];
	if(r-l>1){
	    lz[2*ind]=min(lz[2*ind],lz[ind]);
	    lz[2*ind+1]=min(lz[2*ind+1],lz[ind]);
	}
	lz[ind]=inf;
    }
    void add(int f,int s,int x,int l=0,int r=maxn,int ind=1){
	if(f>=s || l>=r) return;
	get(l,r,ind);
	if(s<=l || r<=f || MX[ind]<=x) return;
	if(f<=l && r<=s && SMX[ind]<x){
	    lz[ind]=x;
	    get(l,r,ind);
	    return;
	}
	int mid=(l+r)>>1;
	add(f,s,x,l,mid,2*ind);
	add(f,s,x,mid,r,2*ind+1);
	Merge(ind);
    }
    void Set(int pos,int x,int l=0,int r=maxn,int ind=1){
	if(l>=r) return;
	get(l,r,ind);
	if(pos<l || pos>=r) return;
	if(r-l==1){
	    cnt[ind]=1;
	    MX[ind]=x;
	    SMX[ind]=-inf;
	    lz[ind]=inf;
	    sm[ind]=x;
	    return;
	}
	int mid=(l+r)>>1;
	Set(pos,x,l,mid,2*ind);
	Set(pos,x,mid,r,2*ind+1);
	Merge(ind);
    }
    ll ask(int f,int s,int l=0,int r=maxn,int ind=1){
	if(f>=s || l>=r) return 0;
	get(l,r,ind);
	if(s<=l || r<=f) return 0;
	if(f<=l && r<=s) return sm[ind];
	int mid=(l+r)>>1;
	return ask(f,s,l,mid,2*ind)+ask(f,s,mid,r,2*ind+1);
    }
};

set<int> fn1,fn2[2];
SMin mn[2];
SBeats mbt[2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<maxn;i++)
	fn1.insert(i);
    int q;cin>>q;
    while(q--){
	int task,l,r,k;
	cin>>task>>l>>r;
	if(task==1){
	    cin>>k;
	    bool bl=k>0;
	    k=abs(k);
	    set<int>::iterator it;
	    while((it=fn1.lower_bound(l))!=fn1.end()){
		if((*it)>=r) break;
		int pt=*it;
		fn1.erase(pt);
		fn2[bl].insert(pt);
		mn[bl].Set(pt,k);
	    }
	    mn[bl].add(l,r,k);
	    while((it=fn2[!bl].lower_bound(l))!=fn2[!bl].end()){
		if((*it)>=r) break;
		int pt=*it;
		fn2[!bl].erase(pt);
		mbt[bl].Set(pt,k);
		mbt[!bl].Set(pt,mn[!bl].ask(pt));
	    }
	    mbt[bl].add(l,r,k);
	}
	else{
	    cout<<mbt[0].ask(l,r)+mbt[1].ask(l,r)<<"\n";
	}
    }
}