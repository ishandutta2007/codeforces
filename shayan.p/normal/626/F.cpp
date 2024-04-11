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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=210;
const ll maxk=1e3+10;
const ll mod=1e9+7;
ll n,k;
ll dp[2][maxn][maxk];
ll a[maxn];

int main(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	dp[1][1][0]=1;
	dp[1][0][0]=1;
	ll o=0,O=1;
	FOR(i,2,n){
		FOR(j,0,n){
			FOR(q,0,k){
				ll num1=q-(j+1)*(a[i-1]-a[i]);
				ll num2=q-(j-1)*(a[i-1]-a[i]);
				ll num3=q-(j)*(a[i-1]-a[i]);
				dp[o][j][q]=0;
				if(0<=num1&&num1<=k)dp[o][j][q]+=dp[O][j+1][num1]*(j+1);//Min
				if(0<=num2&&num2<=k&&j>0)dp[o][j][q]+=dp[O][j-1][num2];//Max
				if(0<=num3&&num3<=k&&j>0)dp[o][j][q]+=dp[O][j][num3]*(j);//joins an existing group
				if(0<=num3&&num3<=k)dp[o][j][q]+=dp[O][j][num3];// itself
				dp[o][j][q]%=mod;
			}
		}
		o++;O++;
		o%=2;O%=2;
	}
	ll ans=0;
	FOR(i,0,k){
		ans+=dp[O][0][i];
		ans%=mod;
	}
	cout<<ans;
}