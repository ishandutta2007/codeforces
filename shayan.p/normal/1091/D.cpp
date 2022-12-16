// Phoenix

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

const int maxn=1e6+10,mod=998244353;

int fac[maxn],dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    dp[1]=0;
    for(int i=2;i<maxn;i++)
	dp[i]=(1ll*i*dp[i-1]+1ll*fac[i]-1ll*i)%mod;
    int n;cin>>n;
    int ans=(1ll*dp[n]+1ll*fac[n])%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}