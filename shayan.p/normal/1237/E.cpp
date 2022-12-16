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

set<int> dp[2];
bool is[2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    
    dp[0].insert(0), dp[1].insert(0), dp[1].insert(1);
    
    for(int i=2;i<=n;i++){
	int x=31-__builtin_clz(i+1);
	if((1<<x) == i+1) continue;
	--x;
	int l=max( (1<<x), i+1-(1<<(x+1)) ), r=i+1-l;

	is[0]= is[1]=0;
	
	for(auto it=dp[0].lower_bound(l-1); it!=dp[0].end() && (*it)<=r-1; it++){
	    int j=(*it)+1;
	    if((j&1)==1 && dp[0].count(i-j)) is[1]=1;
	}
	for(auto it=dp[1].lower_bound(l-1); it!=dp[1].end() && (*it)<=r-1; it++){
	    int j=(*it)+1;
	    if((j&1)==0 && dp[0].count(i-j)) is[0]=1;
	}
	if(is[0]) dp[0].insert(i);
	if(is[1]) dp[1].insert(i);
    }
    return cout<<(dp[0].count(n) || dp[1].count(n))<<"\n",0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")