// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=160;

#pragma GCC Optimize("Ofast")

ll dp[maxn][maxn][maxn],ans[maxn][maxn];// dp: l,r,cnt : az baze l ta r , hamaro bardarim be joz ye palindorm cnt taii
// bedoon hesab kardan pool oon palindorm cnt taii
ll a[maxn];

int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,maxn-1)
		FOR(j,1,maxn-1)
			FOR(k,1,maxn-1)/////
				dp[i][j][k]=-1;
	
	string s;cin>>s;
	s="$"+s;// to make it 1 base
	FORD(l,n,1){
		FOR(r,l,n){
			ll num;
			//cnt>2
			FORD(cnt,(r-l+1),2){
				num=-1;
				FOR(p,l,r-1){
					if(s[p]==s[r]){
						if(dp[l][p-1][0]!=-1&&dp[p+1][r-1][cnt-2]!=-1){
							num=max(num,dp[l][p-1][0]+dp[p+1][r-1][cnt-2]);
						}
					}
				}
				FOR(p,l+1,r){
					if(dp[p][r][0]!=-1&&dp[l][p-1][cnt]!=-1)
						num=max(num,dp[p][r][0]+dp[l][p-1][cnt]);
				}
				dp[l][r][cnt]=num;
			}
			// cnt==1
			num=-1;
			FOR(p,l,r){
				if(dp[l][p-1][0]!=-1&&dp[p+1][r][0]!=-1)
					num=max(num,dp[l][p-1][0]+dp[p+1][r][0]);
			}
			dp[l][r][1]=num;
//			cout<<l<<" "<<r<<" "<<1<<"	"<<num<<endl;
			// cnt==0
			num=-1;
			FOR(p,1,(r-l+1)){
				if(dp[l][r][p]!=-1&&a[p]!=-1)
					num=max(num,dp[l][r][p]+a[p]);
			}
			dp[l][r][0]=num;
//			cout<<l<<" "<<r<<" "<<0<<"	"<<num<<endl;
		}
	}
	FORD(l,n,1){
		FOR(r,l,n){
			ans[l][r]=max(ll(0),dp[l][r][0]);
			FOR(p,l,r){
				ans[l][r]=max(ans[l][r],ans[l][p-1]+ans[p+1][r]);
			}
		}
	}
	cout<<ans[1][n];
}