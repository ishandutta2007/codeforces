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

const int maxn = 5e5 + 10, mod = 1e9 + 7;

int dp1[maxn], dp2[maxn];
vector<int> v[maxn], ds[maxn];
vector<pii> dsp[maxn];

int ans[maxn], arr1[maxn], arr2[maxn];

void mxs(int &a, int b){
    a = max(a, b);
}
void dfsdn(int u, int par = 0){
    for(int y : v[u]){
	if(y != par)
	    dfsdn(y, u), dp1[u] = max( dp1[u], dp1[y] + 1 );
    }
}
void dfsup(int u, int par = 0){  
    int mx1 = -1, mx2 = -1;
    for(int y : v[u]){
	if(y != par){
	    if(mx1 == -1 || dp1[mx1] < dp1[y])
		mx2 = mx1, mx1 = y;
	    else if(mx2 == -1 || dp1[mx2] < dp1[y])
		mx2 = y;
	}
    }
    for(int y : v[u]){
	if(y != par){
	    if(y == mx1){
		dp2[y] = dp2[u] + 1;
		if(mx2 != -1)
		    dp2[y] = max( dp2[y], dp1[mx2] + 2 );
	    }
	    else{
		dp2[y] = max( dp2[u] + 1, dp1[mx1] + 2 );
	    }
	    dfsup(y, u);
	    ds[u].PB( 1 + dp1[y] );	    
	}
    }
    if(par != 0){
	ds[u].PB( dp2[u] );
    }
    sort( ds[u].begin(), ds[u].end(), greater<int>() );
    for(int i = 1; i < sz(ds[u]); i++){
	mxs( arr1[ ds[u][i] ], i+1 );
	if(ds[u][i-1] != ds[u][i])
	    mxs( ans[ 2 * ds[u][i] + 1], i+1 );
    }
    for(int x : ds[u]){
	if(dsp[u].empty() || dsp[u].back().F != x)
	    dsp[u].PB({x,1});
	else
	    dsp[u][ sz(dsp[u]) - 1 ].S ++;
    }
}

void dfs(int u, int par = 0){
    for(int y : v[u]){
	if(y != par){	    
	    dfs(y, u);
	    int cnt1 = 0, cnt2 = 0, val1 = dp1[y] + 1, val2 = dp2[y];
	    auto l1 = dsp[u].begin(), r1 = dsp[u].end();
	    auto l2 = dsp[y].begin(), r2 = dsp[y].end();
	    while(l1 != r1 || l2 != r2){
		pii p;
		if((l2 == r2) || (l1 != r1 && (l1->F) >= (l2->F))){
		    p = *l1, l1++;
		    if(p.F == val1)
			p.S--;
		    cnt1+= p.S;
		}
		else{
		    p = *l2, l2++;
		    if(p.F == val2)
			p.S--;
		    cnt2+= p.S;
		}
		if(cnt1 > 0 && cnt2 > 0)
		    mxs( arr2[p.F], cnt1 + cnt2 );		
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    for(int i = 0; i < n-1; i++){
	int a, b; cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfsdn(1);
    dfsup(1);
    dfs(1);

    if(n > 1){
	mxs( ans[1], 2 );
    }
    for(int i = 1; i <= n; i++){
	mxs( ans[i], 1 );
	mxs( ans[1], sz(v[i])+1 );
    }
    for(int i = n; i >= 1; i--){
	mxs( arr1[i], arr1[i+1] );
	mxs( arr2[i], arr2[i+1] );
	mxs( ans[2 * i], arr2[i]);
	mxs( ans[2 * i], arr1[i] );
	mxs( ans[2 * i -1], arr1[i] );
    }
    for(int i = 1; i <= n; i++){
	cout << ans[i] <<" ";
    }
    return cout << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")