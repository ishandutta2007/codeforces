// Faster!

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

const int maxn=2e5+10,mod=998244353;

vector<int>v[maxn];
int ans[maxn],dp[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1) ans=1ll*ans*a %mod;
    }
    return ans;
}

void dfs(int u){
    int z1=1,z2=1;
    for(int y:v[u]){
	dfs(y);
	z1=1ll*z1*ans[y] %mod;
	z2=1ll*z2*(dp[y]+ans[y]) %mod;
    }
    dp[u]=(z2-z1)%mod;
    ans[u]=z2;
    for(int y:v[u]){
	ans[u]=(1ll*ans[u]-1ll*z1*Pow(ans[y],mod-2) %mod * dp[y])%mod;
    }
    if(sz(v[u])==0) dp[u]=ans[u]=1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=2;i<=n;i++){
	int x;cin>>x;
	v[x].PB(i);
    }
    dfs(1);
    if(ans[1]<0) ans[1]+=mod;
    return cout<<ans[1]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.