// Jump, and you will find out how to unfold your wings as you fall.

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

const int mod=1e9+7;
const ll Big=1e14;

ll Sum(ll l,ll r){
    ll A=r-l+1,B=l+r;
    if((r-l)&1) A>>=1;
    else B>>=1;
    return (A%mod) * (B%mod) %mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m;cin>>n>>m;
    ll pos=1,x=n,ans=1ll*(n%mod)*(m%mod)%mod;
    while(pos<=m){
	ll pos2=m;
	if(x>0) pos2=min(m,n/x);
	ans=(ans-(x %mod)*Sum(pos,pos2))%mod;
	pos=pos2+1,x=n/pos;
    }    
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.