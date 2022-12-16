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

const int maxn=1500+10,Max=1e5+10,mod=1e9+7;
const ll inf=1e18;

int prob[maxn],smp[maxn],smd[maxn][maxn],dp[maxn][maxn],ans[maxn],fac[Max];

ll Sum(){ return 0;}
ll Mul(){ return 1;}
template<typename... types> ll Sum(ll x,types... y) { return ((x%mod) + Sum(y...))%mod; }
template<typename... types> ll Mul(ll x,types... y) { return (x%mod)*Mul(y...)%mod; }

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0] = 1;
    for(int i=1; i<Max; i++){
	fac[i] = Mul( fac[i-1], i );
    }
    int n,m; cin>>n>>m;
    int a,b; cin>>a>>b;
    int p = Mul( a, Pow(b,mod-2) );
    int k; cin>>k;
    for(int i=0; i<=min(k,m); i++){
	prob[i] = Mul( fac[k], Pow(fac[i],mod-2), Pow(fac[k-i],mod-2), Pow(p,i), Pow(1-p,k-i) );
    }
    for(int i=0; i<=m; i++){
	smp[i]=Sum( (i==0 ? 0 : smp[i-1]), prob[i]);
    }
    dp[0][m]=1, ans[0]=1; smd[0][m]=prob[m];
    for(int i=1; i<=n; i++){
	for(int j=1; j<=m ;j++){
	    int A = Mul( prob[m-j], smp[j-1] , Sum(ans[i-1], -dp[i-1][m-j]) );
	    int B = Mul( prob[m-j], smd[i-1][j-1] );
	    dp[i][j] = Sum( dp[i][j-1], A, -B);
	    smd[i][j] = Sum( smd[i][j-1], Mul( dp[i][j], prob[j]) );
	}
	ans[i] = dp[i][m];
    }
    if(ans[n]<0) ans[n]+=mod;
    return cout<<ans[n]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.