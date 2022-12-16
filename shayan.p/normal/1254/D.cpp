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
 
const int maxn=2e5+10, mod=998244353, SQ=310;
const ll inf=1e18;
 
vector<int> v[maxn];
int SZ[maxn];
pii seg[maxn];
int C;
 
vector<pair<pii,int> > vsz[maxn];
 
void prep(int u, int par=-1){
    SZ[u]=1;
    for(int i=0;i<sz(v[u]);i++){
	if(v[u][i] == par){
	    swap( v[u][i], v[u][sz(v[u])-1] );
	    v[u].pop_back();
	    break;
	}
    }
    for(int y:v[u]){
	prep(y, u);
	SZ[u]+= SZ[y];
    }
}
void dfs(int u){
    sort(v[u].begin(), v[u].end() , [](int a, int b){ return SZ[a] < SZ[b]; });
 
    seg[u].F= C++;
    seg[u].S= C;
    
    if(v[u].empty()) return;
    
    int bef=SZ[v[u][0]], id=C;
    for(int y:v[u]){
	if(SZ[y] != bef){
	    vsz[u].PB({ {id, C}, bef});
	    id=C;
	    bef=SZ[y];
	}
	dfs(y);
    }
    vsz[u].PB({ {id, C}, bef});
    seg[u].S= C;
}
 
int SM[maxn], SMQ[maxn];

inline void mkay(int &a, int b){
    a= (a + b) %mod;
}
void add(int pos, int x){
    mkay( SM[pos], x );
    mkay( SMQ[(pos / SQ) + 1], x );
}
void add(int l, int r, int x){
    add(l, x);
    add(r, -x);
}
int ask(int pos){
    int id=pos / SQ, ans=0;
    for(int i=0; i<=id; i++){
	mkay( ans, SMQ[i] );
    }
    for(int i=id * SQ; i<=pos; i++){
	mkay( ans, SM[i] );
    }
    return ans;
}
 
int Pow(int a,int b){
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a %mod)
	if(b&1)
	    ans= 1ll*ans*a %mod;
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
 
    int n,q; cin>>n>>q;
 
    for(int i=0; i<n-1; i++){
	int a,b; cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    prep(1);
    dfs(1);
 
    int iv= Pow(n, mod-2);
 
    while(q--){
	int task; cin>>task;
	if(task==1){
	    int u,d; cin>>u>>d;
	    for(auto p:vsz[u]){
		add(p.F.F, p.F.S, 1ll*d * ( (1ll - 1ll*p.S*iv) %mod ) %mod);
	    }
	    int num = 1ll*d * ( (1ll - 1ll*(n-SZ[u])*iv) %mod ) %mod;
	    add(0, seg[u].F, num);
	    add(seg[u].S, n, num);
	    add(seg[u].F, seg[u].F+1, d);
	}
	else{
	    int u; cin>>u;
	    cout<<( ask( seg[u].F ) + mod ) %mod <<"\n";
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.
 
 
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")