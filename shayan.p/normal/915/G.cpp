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

const int maxn=2e6+10,mod=1e9+7;
const ll inf=1e18;

ll dp[maxn];
vector<int>dv[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=2;i<maxn;i++){
	for(int j=i;j<maxn;j+=i)
	    dv[j].PB(i);
    }
    int ans=0;
    for(int i=1;i<=k;i++){
	dp[i]=dp[i-1]+Pow(i,n)-Pow(i-1,n);
	for(int x:dv[i])
	    dp[i]-=dp[i/x]-(dp[(i-1)/x]);
	dp[i]%=mod;
	if(dp[i]<0) dp[i]+=mod;
	ans=(1ll*ans+(dp[i]^i))%mod;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.