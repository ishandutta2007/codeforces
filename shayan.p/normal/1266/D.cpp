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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

ll d[maxn];
vector<pll> v1, v2;
vector<pair<pii, ll> > ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;
    for(int i=0; i<m; i++){
	int a,b,x; cin>>a>>b>>x;
	d[a]-=x;
	d[b]+=x;
    }
    for(int i=1; i<=n; i++){
	if(d[i]<0){
	    v1.PB({-d[i], i});
	}
	if(d[i]>0){
	    v2.PB({d[i], i});
	}
    }
    while(sz(v1) && sz(v2)){
	pll A = v1.back(), B = v2.back();
	if( A.F == B.F ){
	    v1.pop_back();
	    v2.pop_back();
	    ans.PB({ {B.S, A.S}, A.F });
	    continue;
	}
	if( A.F < B.F ){
	    v2[ sz(v2)-1 ].F -= A.F;
	    v1.pop_back();
	    ans.PB({ { B.S, A.S}, A.F });
	}
	else{
	    v1[ sz(v1)-1 ].F -= B.F;
	    v2.pop_back();
	    ans.PB({ {B.S, A.S}, B.F });
	}
    }
    cout<<sz(ans)<<"\n";
    for(auto p : ans){
	cout<<p.F.S<<" "<<p.F.F<<" "<<p.S<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")