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

const int maxm=3010,maxn=2e5+10,mod=998244353;

int a[maxn],w[maxn],sm[2],n,m;
pii dp[maxm][maxm];

pii operator + (pii a,pii b){
    a.F= (a.F+b.F) %mod;
    a.S= (a.S+b.S) %mod;
    return a;
}
pii operator * (int b,pii a){
    a= { 1ll*a.F*b %mod, 1ll*a.S*b %mod};
    return a;
}

int Pow(int a,int b){
    int ans=1;
    for(; b ; b>>=1, a=1ll*a*a %mod){
	if(b&1) ans=1ll*ans *a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<n;i++)
	cin>>w[i], sm[a[i]]+=w[i];
    for(int i=0;i<=m;i++){
	if(sm[0]-i<0) break;
	dp[i][m-i]={sm[0]-i,sm[1]+m-i};
    }
    for(int s=m-1;s>=0;s--){
	for(int i=0;i<=s;i++){
	    if(sm[0]-i<0) break;
	    int A=sm[0]-i,B=sm[1]+s-i;
	    dp[i][s-i]= Pow(A+B,mod-2) * (A * dp[i+1][s-i] + B*dp[i][s-i+1]);
	}
    }
    for(int i=0;i<n;i++){
	int ans= 1ll* w[i] * Pow(sm[a[i]],mod-2) %mod;
	if(a[i]) ans=1ll*ans*dp[0][0].S %mod;
	else ans=1ll*ans*dp[0][0].F %mod;
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.