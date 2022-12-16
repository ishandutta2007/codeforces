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

const int maxn=1e5+10, mod=1e9 + 7, inf = 1e9;

map<pii, int> mp;
set< pii > st;

vector<int> v[maxn];

void addEdge(int a, int b){
    v[a].PB(b);
    v[b].PB(a);
}
void dfs(pii p){
    st.erase(p);
    while(true){
	auto it = st.lower_bound((pii){p.F, -inf});
	if(it == st.end()) break;
	if(-p.S <= (it->F)) break;
	addEdge( mp[p], mp[*it] );
	dfs(*it);
    }
}

bool mark[maxn];
int ans[maxn];
int SZ[maxn];

void dfsSz(int u, int par=-1){
    SZ[u] = 1;
    for(int y : v[u]){
	if(mark[y]==0 && y!=par)
	    dfsSz(y, u), SZ[u] += SZ[y];
    }    
}
int center(int u, int N, int par=-1){
    for(int y : v[u]){
	if(mark[y]==0 && y!=par && SZ[y] > N)
	    return center(y, N, u);
    }
    return u;
}

void go(int u, int col){
    dfsSz(u);
    u = center(u, SZ[u]/2);
    ans[u] = col;
    mark[u] = 1;
    for(int y : v[u]){
	if(mark[y] == 0)
	    go(y, col+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;
    
    vector<pii> ed(m+1);

    for(int i=0; i<m; i++){
	cin>>ed[i].F>>ed[i].S;
	ed[i].F--, ed[i].S--;
	if(ed[i].F > ed[i].S)
	    swap(ed[i].F, ed[i].S);
    }
    ed[m] = {0, n-1};

    sort( ed.begin(), ed.end(), [](pii a, pii b){ return (a.S != b.S) ? a.S < b.S : a.F < b.F; } );

    for(int i=0; i<sz(ed); i++){
	mp[ { ed[i].F, -ed[i].S } ] = i;
	st.insert( { ed[i].F, -ed[i].S } );
    }
    dfs( {0, -n+1} );
    go(0, 1);

    for(int i=0; i<m+1; i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")