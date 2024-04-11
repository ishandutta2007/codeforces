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

ll dp[maxn][maxn];
pair<ll,pll>p[maxn];// b,a,k

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>p[i].S.F>>p[i].F>>p[i].S.S;
    }
    sort(p+1,p+n+1,greater<pair<ll,pll> >());
    for(int i=0;i<maxn;i++)
	for(int j=0;j<maxn;j++)
	    dp[i][j]=-inf;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
	    dp[i][j]=max(dp[i-1][j]+max(ll(0),p[i].S.F-p[i].F*p[i].S.S),dp[i-1][j-1]+p[i].S.F-p[i].F*(j-1));
	}
	dp[i][0]=dp[i-1][0]+max(ll(0),p[i].S.F-p[i].F*p[i].S.S);
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
	ans=max(ans,dp[n][i]);
    }
    return cout<<ans<<endl,0;
}