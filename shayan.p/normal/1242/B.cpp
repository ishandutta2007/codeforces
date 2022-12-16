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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

set<int> v[maxn];
set<int> in;

void dfs(int u){
    in.erase(u);
    int now=0;
    while(true){
	auto it=in.upper_bound(now);
	while(it!=in.end() && v[u].count(*it)) ++it;
	if(it==in.end()) return;
	now=*it;
	dfs(now);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;
    
    for(int i=1;i<=n;i++)
	in.insert(i);
    for(int i=1;i<=m;i++){
	int a,b; cin>>a>>b;
	v[a].insert(b);
	v[b].insert(a);
    }
    int ans=-1;
    while(sz(in)){
	ans++;
	dfs(*in.begin());
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")