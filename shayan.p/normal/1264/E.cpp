// They can't break me, as long as I know who I am...

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
typedef pair<int, pii> pi3;

const int maxn = 55;
const int MAXN = maxn * maxn, src = MAXN - 1, snk = src - 1;
const int inf = 1e9;

vector<pi3> v[MAXN];
vector<int> vid[MAXN];

int arr[MAXN], par[MAXN], parid[MAXN], ds[MAXN];
bool inq[MAXN];

void add_edge(int a, int b, int w, int c){
    vid[a].PB( sz(v[b]) );
    vid[b].PB( sz(v[a]) );
    v[a].PB( {b, {w, c} } );
    v[b].PB( {a, {0, -c} } );
}
bool spfa(){
    memset( par, -1, sizeof par );
    fill( ds, ds + MAXN, inf);
       
    int L = 0, R = 0;
    arr[ R++ ] = src;
    inq[src] = 1;    
    ds[src] = 0;
   	    
    while(R != L){
	int u = arr[L++];
	if(L == MAXN)
	    L = 0;
	inq[u] = 0;

	for(int i = 0; i < sz(v[u]); i++){
	    auto p = v[u][i];
	    
	    if(p.S.F == 0)
		continue;
	    if( ds[p.F] > ds[u] + p.S.S ){
		ds[p.F] = ds[u] + p.S.S;
		par[p.F] = u;
		parid[p.F] = i;
		if(inq[p.F] == 0){
		    inq[p.F] = 1;
		    arr[ R++ ] = p.F;
		    if( R == MAXN )
			R = 0;
		}
	    }
	}	
    }
    return par[ snk ] != -1;
}
int flow(){
    int ans = 0;
    
    while(spfa()){
	int dad = snk;
	while( dad != src ){
	    int id = parid[dad];
	    int son = dad;	    
	    dad = par[dad];
	    ans+= v[dad][id].S.S;
	    v[dad][id].S.F ^=1;
	    v[son][ vid[dad][id] ].S.F ^= 1;	    
	}
    }
    return ans;
}

bool ans[maxn][maxn];
int dg[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m;
    cin >> n >> m;
    while( m-- ){
	int a, b;
	cin >> a >> b;
	ans[--a][--b] = 1;
	dg[a]++;
    }

    int C = n;

    for(int i = 0; i < n; i++){
	while( dg[i] < n ){
	    add_edge(i, snk, 1, dg[i] );
	    dg[i]++;
	}
    }
    for(int i = 0; i < n; i++){
	for(int j = i+1; j < n; j++){
	    if(ans[i][j] || ans[j][i])
		continue;
	    add_edge(src, C , 1, 0);
	    add_edge(C, i, 1, 0);
	    add_edge(C, j, 1, 0);
	    C++;
	}
    }

    flow();
    
    C = n;
    
    for(int i = 0; i < n; i++){
	for(int j = i+1; j < n; j++){
	    if(ans[i][j] || ans[j][i])
		continue;

	    for(auto p : v[C]){
		if(p.F == src)
		    continue;
		if(p.S.F == 0){
		    if(p.F == i)
			ans[i][j] = 1;
		    else
			ans[j][i] = 1;
		}		    
	    }
	    
	    C++;
	}
    }
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++)
	    cout << ans[i][j];
	cout << "\n";
    }
    return 0;	    
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")