// only miss the sun when it starts to snow

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define y1 STRANGE

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Max=1e6+10, maxn=1e5+10, mod=1e9+7;
    
vector<int> vs[Max],ve[Max];
int rr[maxn], x1[maxn], y1[maxn], x2[maxn], y2[maxn];

struct Segm{
    int val[4*Max];

    Segm(){
	fill(val,val+4*Max,Max);
    }
    void add(int f,int s,int x,int l=0,int r=Max,int id=1){
	if(f>=s || l>=r || s<=l || r<=f) return;
	if(f<=l && r<=s){ val[id]=min(val[id], x); return; }
	int mid=(l+r)>>1;
	add(f,s,x,l,mid,2*id), add(f,s,x,mid,r,2*id+1);
    }
    int ask(int pos,int l=0,int r=Max,int id=1){
	if(r-l==1) return val[id];
	int mid=(l+r)>>1;
	if(pos<mid) return min(val[id], ask(pos,l,mid,2*id) );
	return min(val[id], ask(pos,mid,r,2*id+1));
    }
};Segm segm;

struct Segs{
    int val[4*Max];
    bool zr[4*Max];

    void shiftzr(int l,int r,int id){
	val[id]=0;
	if(r-l>1){
	    zr[2*id]=zr[2*id+1]=1;
	}
	zr[id]=0;
    }
    void shift(int l,int r,int id){
	if(r-l>1){
	    int mid=(l+r)>>1;
	    
	    if(zr[2*id]) shiftzr(l,mid,2*id);
	    if(zr[2*id+1]) shiftzr(mid,r,2*id+1);
	    
	    val[2*id]= (val[2*id] + val[id]) %mod;
	    val[2*id+1]=(val[2*id+1] + val[id]) %mod;
	    val[id]=0;
	}
	if(zr[id]) shiftzr(l,r,id);
    }
    void clr(int f,int s,int l=0,int r=Max,int id=1){
	if(f>=s || l>=r) return;
	shift(l,r,id);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s){ zr[id]=1; return; }
	int mid=(l+r)>>1;
	clr(f,s,l,mid,2*id);
	clr(f,s,mid,r,2*id+1);
    }
    void add(int f,int s,int x,int l=0,int r=Max,int id=1){
	if(f>=s || l>=r) return;
	shift(l,r,id);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s){ val[id]=(val[id]+x)%mod; return; }
	int mid=(l+r)>>1;
	add(f,s,x,l,mid,2*id);
	add(f,s,x,mid,r,2*id+1);
    }    
    int ask(int pos,int l=0,int r=Max,int id=1){
	shift(l,r,id);
	if(r-l==1) return val[id];
	int mid=(l+r)>>1;
	if(pos<mid) return ask(pos,l,mid,2*id);
	return ask(pos,mid,r,2*id+1);
    }
};Segs segs;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m,k; cin>>n>>m>>k;

    for(int i=0;i<k;i++){// 1 base mide dige?
	cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	vs[x2[i]+1].PB(i);
	ve[x1[i]].PB(i);
    }
    x1[k]=2, x2[k]=n, y1[k]=0, y2[k]=0;
    vs[n+1].PB(k);
    ve[2].PB(k);
    k++;

    for(int i=Max-1;i>=0;i--){
	for(int id:vs[i]){
	    segm.add(y1[id], y2[id]+1, x1[id]);
	}
	for(int id:ve[i]){
	    rr[id]= segm.ask(y2[id]+1);
	}
	vs[i].clear(), ve[i].clear();
    }
   
    for(int i=0;i<k-1;i++){///////////
	vs[y1[i]-1].PB(i);
	ve[y2[i]].PB(i);
    }
    ve[0].PB(k-1);///////////////

    segs.add(1,2,1);
    
    for(int i=0;i<m;i++){
	for(int id:vs[i]){
	    segs.clr(x1[id], x2[id]+1);
	    //	    cout<<"CLR "<<i<<" "<<id<<" "<<x1[id]<<" "<<x2[id]<<endl;
	}
	
	vector<int>dp;
	
	for(int id:ve[i]){
	    dp.PB( segs.ask(x1[id]-1) );
	    //	    cout<<"DP "<<i<<" "<<" "<<id<<" "<<x1[id]<<" "<<segs.ask(x1[id]-1)<<endl;
	}
	
	reverse(dp.begin(), dp.end() );

	for(int id:ve[i]){
	    segs.add(x1[id], rr[id], dp.back());
	    //	    cout<<"ADD "<<i<<" "<<id<<" "<<x1[id]<<" "<<rr[id]-1<<" "<<dp.back()<<endl;
	    //	    cout<<"HELLO   "<<id<<" "<<dp.back()<<endl;
	    
	    dp.pop_back();
	}
    }
    return cout<<segs.ask(n)<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")