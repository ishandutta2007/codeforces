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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

ll sm[maxn];
vector<ll> pr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    
    for(int i=0;i<n;i++){
	cin>>sm[i];
	sm[i] = (i==0 ? 0 : sm[i-1]) + sm[i];
    }
    ll x=sm[n-1];
    for(ll i=2;i*i<=x;i++){
	if(x % i==0)
	    pr.PB(i);
	while(x % i==0)
	    x/=i;
    }
    if(x!=1){
	pr.PB(x);
    }
    ll ans=inf;
    for(ll p:pr){
	ll num=0;
	for(int i=0;i<n;i++){
	    num+= min( sm[i] % p, p - (sm[i] % p) );
	}
	ans=min(ans, num);
    }
    if(ans == inf)
	ans=-1;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")