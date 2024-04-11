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

const int maxn=5010,mod=998244353;
const ll inf=1e18;

bool isx[maxn], isy[maxn];
int ansx[maxn], ansy[maxn], dp[maxn][maxn];

int fac[maxn], ifac[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1, a=1ll*a*a %mod)
	if(b&1) ans=1ll*ans*a %mod;
    return ans;
}
int C(int n,int k){
    return 1ll*fac[n] * ifac[k] %mod * ifac[n-k] %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]= 1ll*i* fac[i-1] %mod;
    ifac[maxn-1]= Pow( fac[maxn-1], mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]= 1ll*ifac[i+1] * (i+1) %mod;

    int n,m; cin>>n>>m;
    
    int q; cin>>q;
    while(q--){
	int a,b; cin>>a>>b;
	isx[a]= isy[b]= 1;
	cin>>a>>b;
	isx[a]= isy[b]= 1;
    }
    int fx=0, fy=0;
    for(int i=1;i<=n;i++){
	fx+= isx[i]==0;
    }
    for(int j=1;j<=m;j++){
	fy+= isy[j]==0;
    }
    memset(dp,0,sizeof dp);

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
	dp[i][0]=1;
	for(int j=1;j<=n;j++){
	    dp[i][j]= dp[i-1][j];
	    if(i>1 && isx[i]==0 && isx[i-1]==0){
		dp[i][j]= ( dp[i][j] + dp[i-2][j-1] ) %mod;
	    }
	}	
    }
    for(int i=0;i<=n;i++){
	ansx[i]= dp[n][i];
    }

    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
	dp[i][0]=1;
	for(int j=1;j<=m;j++){
	    dp[i][j]= dp[i-1][j];
	    if(i>1 && isy[i]==0 && isy[i-1]==0){
		dp[i][j]= ( dp[i][j] + dp[i-2][j-1] ) %mod;
	    }
	}	
    }
    for(int i=0;i<=m;i++){
	ansy[i]= dp[m][i];
    }

    ll ans=0;
    
    for(int i=0;i<=n;i++){
	for(int j=0;j<=m;j++){
	    int ffx= fx - 2*i, ffy= fy - 2*j;
	    if(ffx<j || ffy<i) continue;
	    ans= ( 1ll*ans + 1ll* ansx[i] * ansy[j] %mod *C(ffx,j) %mod * C(ffy,i) %mod * fac[j] %mod * fac[i] ) %mod;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")