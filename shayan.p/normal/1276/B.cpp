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

const int maxn = 4e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

int h[maxn], dp[maxn];
vector<int> v[maxn], g[maxn], vec;
bool mark[maxn];
int C, n, SZ[maxn];

void prep(int u){
    mark[u] = 1;
    dp[u] = h[u];
    for(int y : v[u]){
	if(mark[y] == 0){
	    h[y] = h[u] + 1;
	    prep(y);
	    dp[u] = min( dp[u], dp[y] );
	}
	else{
	    dp[u] = min( dp[u], h[y] );
	}
    }
}
void dfs(int u){  
    mark[u] = 1;
    for(int y : v[u]){
	if(mark[y] == 0){
	    int SZ = sz(vec);
	    dfs(y);
	    if( dp[y] >= h[u] ){
		++C;
		while(sz(vec) > SZ){
		    g[C].PB( vec.back() );
		    g[ vec.back() ].PB(C);
		    vec.pop_back();
		}
		g[C].PB(u);
		g[u].PB(C);
	    }
	}
    }
    vec.PB(u);
}
void dfs2(int u, int par=-1){
    SZ[u] = u <= n;
    for(int y : g[u]){
	if(y != par)
	    dfs2(y, u), SZ[u]+= SZ[y];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int m,a,b;
	cin>>n>>m>>a>>b;

	for(int i = 1; i<=n; i++)
	    v[i].clear();
	vec.clear();
	for(int i = 1; i<=2*n; i++)
	    g[i].clear();
	
	for(int i = 0; i < m; i++){
	    int a, b;
	    cin>>a>>b;
	    v[a].PB(b);
	    v[b].PB(a);
	}
	fill(mark, mark + n + 1, 0);
	prep(1);
	C = n;
	fill(mark, mark + n + 1, 0);
	dfs(1);
	
	dfs2(a);
	int A = SZ[b];
	dfs2(b);
	int B = SZ[a];
	cout << 1ll * (A-1) * (B-1) <<"\n";
    }
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")