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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn], b[maxn], ans;
map<pii, int> mp;

void f(int x, int y){
    if( x == 0 ) return;
    ll num = max( ll(0), a[x] - b[x] );
    ans-=num;
    b[x]+= y;
    num = max( ll(0), a[x] - b[x] );
    ans+=num;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n; cin>>n;
    for(int i=1; i<=n; i++){
	cin>>a[i];
	ans+= a[i];
    }
    int q; cin>>q;
    while(q--){
	int x,y,z; cin>>x>>y>>z;
	if(mp.count({x,y})){
	    f( mp[{x,y}], -1 );
	}
	f(z, 1);
	mp[{x,y}] = z;
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")