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

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1, a=1ll*a*a %mod)
	if(b&1) ans=1ll*ans*a %mod;
    return ans;
}

int fac[maxn], ifac[maxn];

int C(int n,int k){
    if(n<0 || k<0 || n<k) return 0;
    return 1ll*fac[n]*ifac[k] %mod * ifac[n-k] %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]= 1ll*fac[i-1]*i %mod;
    ifac[maxn-1]= Pow(fac[maxn-1], mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]= 1ll*ifac[i+1]*(i+1) %mod;
    
    int n,m; cin>>n>>m;
    int ans=1;
    for(int i=1;i<=(n/2);i++){
	ans=(ans + C(n-i,i)) %mod;
    }
    for(int i=1;i<=(m/2);i++){
	ans=(ans + C(m-i,i)) %mod;	
    }
    ans= (2*ans) %mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")