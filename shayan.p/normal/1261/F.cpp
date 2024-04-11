// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define lbt(n) __builtin_ctzll(n)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=4e6+10,mod=998244353;
const ll inf=1e18;
const int BITS=61;

vector<pll> v;
int nxt[maxn][2], C=0;
bool is[maxn];

void bfs(ll f1,ll s1,ll f2,ll s2){
    set< pair<int, pair<pll,pll> > >st1, st2;
    st1.insert({0,{{0,1ll<<BITS},{0,1ll<<BITS}}});
    while(sz(st1)){
	st2.clear();
	for(auto p:st1){
	    auto out=[](ll f,ll s,pll p){ return s<=p.F || p.S<=f; };
	    auto in=[](ll f,ll s,pll p){ return f<=p.F && p.S<=s; };
	    auto mid=[](pll p){ return (p.F+p.S)>>1; };

	    auto add=[&](pair<int, pair<pll,pll> > pp){
		if(out(f1,s1,pp.S.F) || out(f2,s2,pp.S.S)) return 0;
		if(in(f1,s1,pp.S.F) || in(f2,s2,pp.S.S)){
		    is[pp.F]=1;
		    return 1;
		}
		st2.insert(pp);
		return 1;
	    };
	     
	    ll mid1=mid(p.S.F), mid2=mid(p.S.S);
	    
	    bool nw=0;	     
	    if(nxt[p.F][0]==0) nxt[p.F][0]=++C, nw=1;
	    assert(C<maxn);///////
	    
	    bool A=add( {nxt[p.F][0], { {p.S.F.F, mid1}, {p.S.S.F, mid2} } } );
	    bool B=add( {nxt[p.F][0], { {mid1, p.S.F.S}, {mid2, p.S.S.S} } } );

	    if( A==0 && B==0 && nw )
		nxt[p.F][0]=0, --C;
	    
	    nw=0;
	    if(nxt[p.F][1]==0) nxt[p.F][1]=++C, nw=1;
	    assert(C<maxn);/////////
	    
	    A=add( {nxt[p.F][1], { {p.S.F.F, mid1}, {mid2, p.S.S.S} } } );
	    B=add( {nxt[p.F][1], { {mid1, p.S.F.S}, {p.S.S.F, mid2} } } );	    
	    
	    if( A==0 && B==0 && nw )
		nxt[p.F][1]=0, --C;
	}
	st1=st2;
    }
}

ll ans;

void dfs(int u=0,ll num=0,int bt=BITS){
    if(is[u]){
	ll x=(1ll<<bt)%mod;	
	ans= ( 1ll*ans + ( 1ll*num*x %mod * x ) +  ( 1ll*(x-1)*x %mod * ((mod+1)/2) ))%mod;
	return;
    }
    if(nxt[u][0]!=0) dfs(nxt[u][0], (num<<1)%mod, bt-1);
    if(nxt[u][1]!=0) dfs(nxt[u][1], (1|(num<<1))%mod, bt-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int N; cin>>N;
    for(int i=0;i<N;i++){
	ll l,r; cin>>l>>r;
	v.PB({l, ++r});
    }
    cin>>N;
    for(int i=0;i<N;i++){
	ll l,r; cin>>l>>r;
	++r;
	for(pll p:v){
	    bfs(l, r, p.F, p.S);
	}
    }
    dfs();
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")