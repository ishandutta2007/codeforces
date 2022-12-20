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

const int maxn=5010,mod=1e9+7;
const ll inf=1e18;

int dp[maxn][maxn],ans[maxn][maxn],a[maxn],n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int j=0;j<n;j++){
	dp[j][j]=ans[j][j]=a[j];
	for(int i=j-1;i>=0;i--)
	    dp[i][j]=dp[i+1][j]^dp[i][j-1],ans[i][j]=max(dp[i][j],max(ans[i+1][j],ans[i][j-1]));
	
    }
    int q;cin>>q;
    while(q--){
	int l,r;cin>>l>>r;
	cout<<ans[--l][--r]<<"\n";
    }
}