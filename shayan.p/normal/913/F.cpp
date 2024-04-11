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

const int maxn=2010,mod=998244353;

int dp[maxn],comp[maxn],choose[maxn][maxn];

inline int C(int n){
    return (n*(n-1))/2;
}

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
    
    int n,a,b;cin>>n>>a>>b;
    int p=1ll*a*Pow(b,mod-2) %mod;
    for(int i=1;i<=n;i++){
	choose[i][0]=choose[i][i]=1;
    }
    for(int i=1;i<=n;i++){
	for(int j=1;j<i;j++){
	    choose[i][j]=(1ll*choose[i-1][j]*Pow(1-p,j) + 1ll*choose[i-1][j-1]*Pow(p,i-j))%mod;
	}
    }
    for(int i=1;i<=n;i++){
	comp[i]=1;
	for(int j=1;j<i;j++){
	    comp[i]=(1ll*comp[i]-1ll*choose[i][j]*comp[j])%mod;
	}
    }
    for(int i=2;i<=n;i++){
	for(int j=1;j<i;j++){
	    int A=(dp[j]+dp[i-j]+C(i)-C(i-j))%mod;
	    dp[i]=(1ll*A*comp[j] %mod *choose[i][j]+1ll*dp[i])%mod;
	}
	dp[i]=1ll*(1ll*dp[i]+1ll*comp[i]*C(i))%mod *Pow(1-comp[i],mod-2)%mod;
    }
    if(dp[n]<0) dp[n]+=mod;
    cout<<dp[n]<<endl;
    return 0;
}