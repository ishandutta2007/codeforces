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

ll f(ll x){
    for(ll i=2;i*i<=x;i++){
	if(x%i==0) return i;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    ll n; cin>>n;
    if(n==1) return cout<<1<<endl,0;
    ll x=f(n);
    while(n%x==0) n/=x;
    if(n==1) return cout<<x<<endl,0;
    else return cout<<1<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")