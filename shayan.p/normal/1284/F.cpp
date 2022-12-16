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

const int maxn = 25e4 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

vector<int> v[maxn];
int SZ[maxn];
bool mark[maxn];

void dfsSZ(int u, int par = -1){
    SZ[u] = 1;
    for(int y : v[u]){
	if(y != par && mark[y] == 0)
	    dfsSZ(y, u), SZ[u]+= SZ[y];
    }
}
int dfsCn(int u, int N, int par = -1){
    for(int y : v[u]){
	if(y != par && mark[y] == 0 && SZ[y] > N)
	    return dfsCn(y, N, u);
    }
    return u;
}

vector< pair<int, pii> > g[maxn];
vector< pair< pii, pii > > ANS;

int col[maxn];
pair<int, pii> pr[maxn];
int tp[maxn], tp2[maxn];

void go(int u, function<void(int)> f, int par = -1){
    f(u);
    for(int y : v[u]){
	if(y != par && mark[y] == 0)
	    go(y, f, u);
    }
}
void dfs(int u, int par = -1){
    for(auto p : g[u]){
	if(p.F != par)
	    pr[p.F] = {u, p.S}, dfs(p.F, u);
    }
}

void solve(vector< pair<pii, pii> > &ed, int r){// < ed asli, ed new >    
    dfsSZ(r);
    r = dfsCn(r, SZ[r]/2);
    go(r, [&](int u){ g[u].clear(); } );
    for(auto p : ed){
	g[p.S.F].PB({p.S.S, p.F});
	g[p.S.S].PB({p.S.F, p.F});
    }
    int C = 0;
    for(int y : v[r]){
	if(mark[y] == 0){
	    go(y, [&](int u){ col[u] = C; }, r);
	    C++;
	}
    }
    dfs(r);
    col[r] = -1;

    C = 0;
    for(int y : v[r]){
	if(mark[y] == 0){
	    int tmp = y;
	    while(col[tmp] == col[ pr[tmp].F ])
		tmp = pr[tmp].F;
	    tp[C] = tmp;
	    tp2[C] = y;
	    C++;
	}
    }
    
    vector< vector< pair<pii, pii> > > vec(C);

    go(r, [&](int u){
	      if(u == r)
		  return;
	      if(tp[ col[u] ] == u){
		  ANS.PB( { pr[u].S, { tp2[ col[u] ], r } } );
		  return;
	      }
	      if(col[ pr[u].F ] != col[u]){
		  vec[ col[u] ].PB({ pr[u].S, {u, tp2[ col[u] ]} });
	      }
	      else{
		  vec[ col[u] ].PB({ pr[u].S, {u, pr[u].F} });
	      }
	  });
    mark[r] = 1;
    for(int y : v[r]){
	if(mark[y] == 0){
	    solve( vec[ col[y] ], y );
	}	    
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b; cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    vector<pair<pii, pii> > vec;
    for(int i = 0; i < n-1; i++){
	int a, b; cin >> a >> b;
	vec.PB({ {a, b}, {a, b} });	
    }
    solve(vec, 1);
    cout << n-1 <<"\n";
    for(auto p : ANS){
	cout << p.S.F << " " << p.S.S << " " << p.F.F << " " << p.F.S <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")