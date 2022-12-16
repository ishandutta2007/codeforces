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

const int maxn=1e5+10;
const ll inf = 1e18, Big = 314000000;;

vector<int> rule[maxn], rev[maxn];
int who[maxn], del[maxn], ones[maxn];

vector<int> v[maxn];

ll dp1[maxn], dp2[maxn], cost[maxn];

bool bad[maxn], badr[maxn];
int mark[maxn];

void dfs(int u){
    mark[u] = 1;
    for(int r : v[u]){
	if(badr[r])
	    continue;
	ll num = ones[r];
	for(int y : rule[r]){
	    if( mark[y] == 1 ){
		bad[u] = 1;
	    }
	    if( mark[y] == 0 ){
		dfs(y);
	    }
	    bad[u] |= bad[y];

	    num += dp2[y];
	    num = min( num, Big );
	}
	dp2[u] = max( dp2[u], num );	
    }
    mark[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int m, n;
    cin >> m >>n;
    for (int i=0; i<m; i++){
	int u;
	cin>>u;
	--u;
	v[u].PB(i);
	who[i] = u;
	int q;
	cin>>q;
	while(q--){
	    int x;
	    cin>>x;
	    if(x == -1)
		cost[i]++, ones[i]++;
	    else
		--x, rule[i].PB(x), rev[x].PB(i);	    	       
	}
    }

    priority_queue<pll, vector<pll>, greater<pll> > pq;

    for(int i=0; i<n; i++){
	dp1[i] = inf;
	for(int j : v[i])
	    if(rule[j].empty())
		dp1[i] = min( dp1[i], cost[j] );
	if(dp1[i] != inf)
	    pq.push({ dp1[i], i} );
    }

    while(sz(pq)){
	int u = pq.top().S;
	pq.pop();

	if(mark[u]) continue;
	mark[u] = 1;
	
	for(int y : rev[u]){
	    cost[y]+= dp1[u];
	    cost[y] = min( cost[y], Big );
	    if( ++del[y] == sz( rule[y] ) ){
		if(dp1[ who[y] ] > cost[y])
		    dp1[ who[y] ]= cost[y], pq.push( { cost[y], who[y] } );
	    }
	}
    }
    memset(mark, 0, sizeof mark);

    for(int i=0; i<n; i++){
	if(dp1[i] == inf){
	    mark[i] = 2;
	    for(int u : rev[i])
		badr[u] = 1;
	}
    }
    for(int i=0; i<n; i++){
	if(mark[i] == 0)
	    dfs(i);
    }

    for(int i=0; i<n; i++){
	if(dp1[i] == inf)
	    cout<<-1<<" "<<-1<<"\n";
	else if(bad[i])
	    cout<<dp1[i]<<" "<<-2<<"\n";
	else
	    cout<<dp1[i]<<" "<<dp2[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")