// Remember...

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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int t[maxn], d[maxn];

ll mx[4*maxn], lz[4*maxn];

void shift(int l,int r,int id){
    mx[id]+= lz[id];
    if(r-l>1){
	lz[2*id]+= lz[id];
	lz[2*id+1]+= lz[id];
    }
    lz[id]=0;
}
void add(int f,int s,int x,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]=x; shift(l,r,id); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
    mx[id]= max(mx[2*id], mx[2*id+1]);    
}
ll ask(int f,int s,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r) return 0;
    shift(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return mx[id];
    int mid=(l+r)>>1;
    return max( ask(f,s,l,mid,2*id), ask(f,s,mid,r,2*id+1) );
}

ll fn[maxn];

void add2(int pos,int x){
    for(pos+=3; pos<maxn; pos+= pos & -pos)
	fn[pos]+=x;
}
ll ask2(int pos){
    ll ans=0;
    for(pos+=3; pos>0; pos-= pos & -pos)
	ans+= fn[pos];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    for(int i=1;i<=q;i++){
	string task; cin>>task;
	if(task == "+"){
	    cin>>t[i]>>d[i];
	    add(t[i],t[i]+1, t[i]);
	    add(0,t[i]+1,d[i]);
	    add2(t[i],d[i]);
	}
	if(task == "-"){
	    int x; cin>>x;
	    add(t[x], t[x]+1, -t[x]);
	    add(0,t[x]+1, -d[x]);
	    add2(t[x],-d[x]);
	}
	if(task == "?"){
	    int x; cin>>x;
	    cout<<max(ll(0), ask(0,x+1)-x -ask2(maxn-5) + ask2(x))<<endl;
	}
    }
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")