// Wanna Hack? GL...

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

const int maxn=510,mod=1e9+7;
const ll inf=1e18;

int dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for(int r=0;r<n;r++){
	dp[r][r]=1;
	for(int l=r-1;l>=0;l--){
	    dp[l][r]=dp[l][r-1]+1;
	    for(int pos=l;pos<r;pos++){
		if(s[pos]==s[r])
		    dp[l][r]=min(dp[l][r],dp[l][pos]+dp[pos+1][r-1]);
	    }
	}
    }
    return cout<<dp[0][n-1]<<endl,0;
}