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
typedef long double ld;

const int maxn=1e5+10,mod=1e9+7;

int a[maxn],dp[maxn];

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,N=0;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	N+=a[i];
    }
    dp[1]=1ll*(1ll*(N-2)*N+1)%mod * Pow(N,mod-2) %mod;
    for(int i=2;i<maxn;i++)
	dp[i]=(2ll*dp[i-1]-1ll*dp[i-2]-1ll*(N-1)*Pow(N-i+1,mod-2))%mod;
    int ans=0;
    for(int i=0;i<n;i++)
	ans=(ans+dp[a[i]])%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}