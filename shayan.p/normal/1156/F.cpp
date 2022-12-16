// High above the clouds there is a rainbow...

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

const int maxn=5010,mod=998244353;

int cnt[maxn],n;
int iv[maxn],dp[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1) ans=1ll*ans*a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
	iv[i]=Pow(i,mod-2);
    }
    for(int i=0;i<n;i++){
	int x;cin>>x;
	cnt[x]++;
    }
    dp[0]=1;
    int ans=0;
    for(int i=1;i<=n;i++){
	for(int j=n-1;j>=0;j--){
	    int x= 1ll* dp[j] * cnt[i] %mod * iv[n-j] %mod;
	    if(j!=n-1) ans=(1ll*ans+ 1ll*x* (cnt[i]-1) %mod * iv[n-j-1] )%mod;
	    dp[j+1]=(dp[j+1]+x)%mod;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.