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

const int maxn = 3010, mod = 1e9 + 7;
const ll inf = 1e18;

int a[maxn];
vector<int> v[maxn];
vector<pll> dp[maxn];

void dfs(int u, int par = -1){
    dp[u].PB({ 0, a[u] });    
    for(int y : v[u]){
	if(y != par){
	    dfs(y, u);
	    vector<pll> vec( sz(dp[u]) + sz(dp[y]) );
	    for(int i = 0; i < sz(dp[u]) + sz(dp[y]); i++)
		vec[i] = {-1, -1};
	    for(int i = 0; i < sz(dp[u]); i++)
		for(int j = 0; j < sz(dp[y]); j++){
		    pll A = dp[u][i], B = dp[y][j];
		    vec[i + j +1] = max( vec[i + j +1], (pll) {A.F + B.F + (B.S > 0), A.S} );
		    vec[i + j] = max( vec[i + j], (pll){ A.F + B.F , A.S + B.S } );
		}
	    dp[u] = vec;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	    v[i].clear(), dp[i].clear();
	for(int i = 1; i <= n; i++)
	    cin >> a[i];
	for(int i = 1; i <= n; i++){
	    int x;
	    cin >> x;
	    a[i] = x - a[i];
	}
	for(int i = 0; i < n-1; i++){
	    int a, b;
	    cin >> a >> b;
	    v[a].PB(b);
	    v[b].PB(a);
	}
	dfs(1);
	cout << dp[1][m-1].F + (dp[1][m-1].S > 0) <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")