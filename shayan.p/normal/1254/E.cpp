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
typedef long double ld;

const int maxn = 5e5 + 10, mod = 1e9 + 7;

vector<int> v[maxn];
vector<pii> vec;
int f[maxn];

int pr[maxn], h[maxn];

vector<int> up, dn;
map<int, int> nx[maxn];
int gg[maxn], pp[maxn];

bool su[maxn], sd[maxn];

void no(){
    cout << 0 << endl;
    exit(0);
}
void prep(int u, int par=0){
    pr[u] = par;
    h[u] = 1 + h[par];
    for(int y : v[u]){
	if(y != par)
	    prep(y, u);
    }
}
void lca(int a, int b){
    up.clear(), dn.clear();
    
    while(h[a] > h[b])
	up.PB(a), a = pr[a];
    while(h[b] > h[a])
	dn.PB(b), b = pr[b];
    while(a != b){
	up.PB(a);
	dn.PB(b);
	a = pr[a];
	b = pr[b];
    }
    reverse( dn.begin(), dn.end() );
}

int fac[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] %mod;
    
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a,b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i = 1; i <= n; i++){
	int x;
	cin >> x;
	if(x != 0){
	    if(f[x] != 0)
		no();
	    if( x == i )
		no();
	    f[x] = i;
	    vec.PB({ x, i } );
	}
    }
    
    prep(1);
    
    for( pii p : vec ){
	lca(p.F, p.S);

	for(int x : up){
	    if(su[x])
		no();
	    su[x] = 1;	    
	}
	for(int x : dn){
	    if(sd[x])
		no();
	    sd[x] = 1;	    
	}

	if(sz(up)){
	    pp[ up[0] ] = pr[ up[0] ];
	}
	else{
	    pp[ pr[ dn[0] ] ] = dn[0];
	}
	
	if(sz(dn)){
	    gg[ dn.back() ] = pr[ dn.back() ];
	    
	    for(int i = 0; i < sz(up); i++){
		nx[ pr[ up[i] ] ][ up[i] ] = i == sz(up) - 1 ? dn[0] : pr[ up[i+1] ];
	    }
	    for(int i = 0; i < sz(dn)-1; i++){
		nx[ dn[i] ][ pr[ dn[i] ] ] = dn[i+1];
	    }
	}
	else{
	    gg[ pr[ up.back() ] ] = up.back();

	    for(int i = 0; i < sz(up)-1; i++){
		nx[ pr[ up[i] ] ][ up[i] ] = pr[ up[i+1] ];				
	    }
	}	
    }
    
    int ans = 1;
    for(int u = 1; u <= n; u++){
	bool P= pp[u] != 0 , G= gg[u] != 0;
	int cnt = sz( nx[u] ), cnt2 = 1;
	
	if( sz(v[u]) == 1 )
	    continue;
	if( P & G ){
	    int tmp = pp[u];
	    while( nx[u].count(tmp) )
		tmp = nx[u][tmp], cnt2++;
	    if( tmp == gg[u] && cnt2 != sz(v[u]) )
		no();
	}
	ans = 1ll * ans * fac[ max(int(0), sz(v[u]) - G - P - cnt) ] %mod;

	for(int y : v[u]){
	    if( nx[u].count(y) == 0 )
		continue;
	    int tmp = nx[u][y];
	    while( nx[u].count(tmp) ){
		int tmp2 = nx[u][tmp];
		if(tmp2 == y)
		    no();
		nx[u].erase(tmp);
		tmp = tmp2;
	    }	    
	}
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")