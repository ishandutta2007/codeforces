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

const int maxn=5010,mod=1e9+7;
const ll inf=1e18;

string s;
int sm[maxn][maxn], dp[maxn][maxn], n, cmp[maxn][maxn];
pair<pii,int> arr[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n>>s;

    for(int i=1;i<=n;i++){
	for(int j=0;j<n-i+1;j++){
	    arr[j]= { { cmp[i-1][j], s[j+i-1]-'0' }, j };
	}
	sort(arr,arr+n-i+1);
	for(int j=1;j<n-i+1;j++){
	    cmp[i][ arr[j].S ]= cmp[i][ arr[j-1].S ] + (arr[j-1].F!=arr[j].F);
	}
    }
    
    for(int i=1;i<=n;i++){
	dp[i][i]= s[0]!='0';
	for(int j=1;j<i;j++){
	    dp[i][j]= s[i-j]=='0' ? 0 : ( sm[i-j][j-1] + ( i-j-j>=0 && s[i-j-j]!='0' && cmp[j][i-j-j]<cmp[j][i-j] ? dp[i-j][j] : 0 ) );
	    dp[i][j]%=mod;
	}
	for(int j=1;j<=n;j++){
	    sm[i][j]= sm[i][j-1] + dp[i][j];
	    sm[i][j]%=mod;
	}
    }
    return cout<<sm[n][n]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")