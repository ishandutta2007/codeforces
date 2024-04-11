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

const int maxn=2010,mod=1e9+7;

int dp[2][maxn][maxn],DP[maxn][maxn],SDP[maxn][maxn],n,k;
string s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k>>s;
    DP[0][0]=1;
    for(int i=1;i<=n;i++){
	for(int j=0;j<=k;j++){
	    dp[0][i][j]= 1ll * (s[n-i]-'a') * DP[i-1][j] %mod;
	    dp[1][i][j]= 1ll * ('z'-s[n-i]) * (j>=i ? DP[i-1][j-i] : 0) %mod;
	    SDP[i][j]= (SDP[i-1][j] + dp[0][i][j]) %mod;
	    DP[i][j]= (SDP[i][j] + (j==0)) %mod;
	    int w=0;
	    for(;w<i && w*(i-w)<=j;w++)
		DP[i][j]= (DP[i][j] + dp[1][i-w][j-w*(i-w)]) %mod;
	    for(int ww=i-1; ww*(i-ww)<=j && ww>=w;ww--)
		DP[i][j]= (DP[i][j] + dp[1][i-ww][j-ww*(i-ww)]) %mod;
	}
    }
    if(DP[n][k]<0) DP[n][k]+=mod;
    return cout<<DP[n][k]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.