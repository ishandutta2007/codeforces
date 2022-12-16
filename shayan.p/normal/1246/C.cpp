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

const int maxn=2010, mod=1e9+7;

int dp[maxn][maxn][2], sm[maxn][maxn][2], cnt[maxn][maxn][2];
bool is[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
	string s; cin>>s;
	for(int j=0;j<m;j++){
	    is[i][j]= s[j]=='R';
	}
    }
    if(n==1 && m==1) return cout<<1<<endl,0;
    for(int i=n-1;i>=0;i--){
	for(int j=m-1;j>=0;j--){
	    cnt[i][j][0]= cnt[i][j+1][0] + is[i][j];
	    cnt[i][j][1]= cnt[i+1][j][1] + is[i][j];
	}
    }
    sm[n-1][m-1][0]= sm[n-1][m-1][1]= dp[n-1][m-1][0]= dp[n-1][m-1][1]= 1;
    for(int i=n-1;i>=0;i--){
	for(int j=m-1;j>=0;j--){
	    if(i==n-1 && j==m-1) continue;
	    if(cnt[i][j+1][0] < m-j-1) dp[i][j][0]= ( sm[i][j+1][1] - sm[i][m-cnt[i][j+1][0]][1] ) %mod;
	    if(cnt[i+1][j][1] < n-i-1) dp[i][j][1]= ( sm[i+1][j][0] - sm[n-cnt[i+1][j][1]][j][0] ) %mod;
	    sm[i][j][0]= (sm[i+1][j][0] + dp[i][j][0]) %mod;
	    sm[i][j][1]= (sm[i][j+1][1] + dp[i][j][1]) %mod;
	}
    }
    int ans= (dp[0][0][0] + dp[0][0][1]) %mod;
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")