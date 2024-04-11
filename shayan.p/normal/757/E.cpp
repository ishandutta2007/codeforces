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

const int maxn=1e6+10,Log=23,mod=1e9+7;

int dp[maxn][Log],par[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=2;i<maxn;i++){
	if(par[i]==0){
	    for(int j=i;j<maxn;j+=i)
		par[j]=i;
	}
    }
    dp[0][0]=1;
    for(int i=1;i<Log;i++){
	dp[0][i]=2;
    }
    for(int r=1;r<maxn;r++){
	dp[r][0]=1;
	for(int i=1;i<Log;i++)
	    dp[r][i]=(dp[r][i-1]+dp[r-1][i])%mod;
    }
    int q;cin>>q;
    while(q--){
	int r,a,ans=1;cin>>r>>a;
	while(a>1){
	    int p=par[a],c=0;
	    while(a%p==0) c++,a/=p;
	    ans=1ll*ans*dp[r][c] %mod;
	}
	cout<<ans<<"\n";
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.