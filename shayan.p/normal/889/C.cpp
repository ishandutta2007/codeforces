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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int sm[maxn], dp[maxn];

int Pow(int a,int b){
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a %mod)
	if(b&1) ans=1ll*ans*a %mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,k,ans=1; cin>>n>>k;  --n;

    sm[0]=dp[0]=1;
    for(int i=1;i<=k;i++){
	dp[i]= 1ll*Pow(i,mod-2) * sm[i-1] %mod;
	sm[i]= (sm[i-1] + dp[i]) %mod;
	ans=1ll*ans*i %mod;
    }
    for(int i=k+1;i<=n;i++){
	dp[i]= 1ll*Pow(i,mod-2) *(sm[i-1] - sm[i-k-1]) %mod;
	sm[i]= ( sm[i-1] + dp[i] ) %mod;
	ans=1ll*ans*i %mod;
    }
    ans=1ll*ans* (n+1-sm[n]) %mod;
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")