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

const int maxn=2e5+10,mod=998244353,inf=1e9;

set<pii>st[maxn];
int lzx[4*maxn],lzz[4*maxn],val[4*maxn],n;

void get(int l,int r,int id){
    val[id]=(1ll*val[id]*lzz[id]+1ll*(r-l)*lzx[id])%mod;
    if(r-l>1){
	lzz[2*id]= 1ll*lzz[2*id]*lzz[id] %mod;
	lzz[2*id+1]= 1ll*lzz[2*id+1]*lzz[id] %mod;
	lzx[2*id]= (1ll*lzx[id] + 1ll*lzx[2*id]*lzz[id]) %mod;
	lzx[2*id+1]= (1ll*lzx[id] + 1ll*lzx[2*id+1]*lzz[id]) %mod;
    }
    lzz[id]=1,lzx[id]=0;
}
void Mul(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lzz[id]=2; get(l,r,id); return; }
    int mid=(l+r)>>1;
    Mul(f,s,l,mid,2*id);
    Mul(f,s,mid,r,2*id+1);
    val[id]=(val[2*id]+val[2*id+1])%mod;
}
void Add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lzx[id]=x; get(l,r,id); return; }
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    val[id]=(val[2*id]+val[2*id+1])%mod;
}
int Ask(int f,int s,int  l=0,int r=n,int id=1){
    if(f>=s || l>=r) return 0;
    get(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return (Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fill(lzz,lzz+4*maxn,1);
    int q;cin>>n>>q;
    while(q--){
	int task,l,r;cin>>task>>l>>r; --l;
	if(task==1){
	    int x;cin>>x;
	    auto it=st[x].upper_bound((pii){l,inf});
	    if(it!=st[x].begin()) --it;
	    while(it!=st[x].end() && (it->F)<r){
		int L=it->F,R=it->S;
		it=next(it);
		int LL=max(L,l),RR=min(R,r);
		if(LL>=RR) continue;
		Mul(LL,RR),Add(LL,RR,-1);
		st[x].erase(prev(it));
		if(L<LL) st[x].insert({L,LL});
		if(RR<R) st[x].insert({RR,R});
	    }
	    st[x].insert({l,r});
	    Add(l,r,1);
	}
	else{
	    cout<<Ask(l,r)<<"\n";
	}
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.