// only miss the sun when it starts to snow

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

ll a[maxn];
vector<pair<ll,int> > vec;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m; cin>>n>>m;

    for(int i=0;i<n;i++){
	cin>>a[i];
    }

    ll ans=0;
    
    for(int k=1;k<=(m/n);k++){
	ll ANS=0;

	vec.clear();
	int mm= m - k*n;
	for(int i=n-1;i>=0;i--){
	    ll num= a[i] - 1ll* (1ll*k*(k+1)/2) * n + (n-1-i)*k;
	    ANS+= a[i] - num;
  
	    if(num<0) goto Hell;
	    if( vec.empty() || num<vec.back().F ) vec.PB({num,n-i-1});
	    vec[sz(vec)-1].S++;
	}
	
	reverse(vec.begin(), vec.end());

	int cnt=0;
	
	if( 1ll*mm*(k-1) < vec[0].F ) cnt= min( ll(mm), vec[0].F - 1ll*mm*(k-1) );
	
	int mmm= mm - cnt;

	for(int i=1;i<sz(vec);i++){
	    int x= min(ll(mmm), vec[i].F - vec[i-1].F);
	    mmm-=x;
	    ANS+= 1ll*vec[i].S *x;
	}
	ANS+= 1ll* n * min( vec[0].F, 1ll*mm*(k-1) + cnt );
	ans= max(ans, ANS);
    }
 Hell:;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")