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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

int n,m,c, sm;
pair<int,pii> p[maxn];

set<pii> st; // gheimat , index

int val[4*maxn], lz[4*maxn];

void shift(int l,int r,int id){
    val[id]+= lz[id];
    if(r-l>1)
       lz[2*id]+= lz[id], lz[2*id+1]+= lz[id];
    lz[id]=0;
}
void add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]+=x; shift(l,r,id); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
    val[id]= max( val[2*id], val[2*id+1] );
}
int ask(int f,int s,int l=0,int r=n,int id=1){// farthest maximum
    if(f>=s || l>=r) return -1;
    shift(l,r,id);
    if(s<=l || r<=f) return -1;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return max( ask(f,s,l,mid,2*id), ask(f,s,mid,r,2*id+1) );
}
int fnd(int x,int l=0,int r=n,int id=1){
    shift(l,r,id);
    if(val[id]!=x) return -1;
    if(r-l==1) return l;
    int mid=(l+r)>>1;
    if(val[2*id+1] + lz[2*id+1] == x) return fnd(x,mid,r,2*id+1);
    else                              return fnd(x,l,mid,2*id);
}

void input(){
    st.clear();   
    cin>>n>>m>>c>>sm;
    for(int i=0;i<4*n + 10;i++)
	val[i]= lz[i]= 0;
    for(int i=0;i<n;i++)
	cin>>p[i].F>>p[i].S.F>>p[i].S.S;    
    sort(p,p+n);
}
int CNT=0;
ll solve(){
    int L=0, R=0;
    ll ans=0;
    while(sm<m){
	while(R<n && p[R].F<=sm){
	    add(R,R+1, sm - p[R].F);
	    st.insert({p[R].S.S,R});
	    R++;
	}
	if(L>=R) return -1;
	if(ask(L,R) == c){
	    int pos= fnd(c);
	    while(L<=pos)
		st.erase({p[L].S.S,L}), L++;
	}
	while(sz(st) && p[st.begin()->S].S.F==0){
	    st.erase(st.begin());	    
	}
	if(st.empty()) return -1;
	int id=st.begin()->S;
	int can= min( p[id].S.F, c - ask(id,R) );
	can=min(can, (R==n ? m : p[R].F) - sm);
	p[id].S.F-= can;
	sm+= can;
	add(id, R, can);
	ans+= 1ll*can * p[id].S.S;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	input();
	cout<<solve()<<"\n";
    }
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")