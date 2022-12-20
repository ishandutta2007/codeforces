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

const int maxn=5010,mod=1e9+7;
const ll inf=1e18;

int n,a[maxn],dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    n=unique(a,a+n)-a;
    for(int l=1;l<n;l++){
	for(int r=n-2;r>=l;r--){
	    dp[l][r]=max(dp[l-1][r],max(dp[l][r+1],(a[l-1]==a[r+1])+dp[l-1][r+1]));
	}
    }
    int ans=n-1;
    for(int i=0;i<n;i++){
	ans=min(ans,n-1-dp[i][i]);
    }
    return cout<<ans<<endl,0;
}