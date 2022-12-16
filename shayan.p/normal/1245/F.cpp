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

vector<pii> v;

ll solve(int l,int r){
    if(l==0 && r==0) return 0;
    int bt=31;
    while(bit(l,bt)==0 && bit(r,bt)==0) bt--;
    if(bit(l,bt) && bit(r,bt)) return 0;
    v.clear();
    v.PB({l,0}); v.PB({r,0});
    for(int i=bt-1;i>=0;i--){
	if(bit(l,i)==0)
	    v.PB({ (l ^ (1<<i)) & (((1<<30)-1)<<i), i });
    }
    for(int i=bt-1;i>=0;i--){
	if(bit(r,i))
	    v.PB({ (r ^ (1<<i)) & (((1<<30)-1)<<i), i });
    }
    ll ans=0;
    for(auto x:v){
	for(auto y:v){
	    if(x.F & y.F) continue;
	    ll num=1;
	    for(int i=bt-1;i>=0;i--){
		if(x.S>i && y.S>i) num*=3;
		else if(x.S>i) num*= bit(y.F,i) ? 1 : 2;
		else if(y.S>i) num*= bit(x.F,i) ? 1 : 2;
	    }
	    ans+=num;
	}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;
    while(q--){
	int l,r; cin>>l>>r;
	cout<<solve(l,r)<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")