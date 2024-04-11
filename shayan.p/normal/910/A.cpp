// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

const ll inf=1e18;
const ll maxn=2e2+10;

ll dp[maxn];
int main(){
	ll n,d;cin>>n>>d;
	string s;cin>>s;
	FOR(i,1,n-1){//dp[0]=0;
		if(s[i]=='0')continue;
		dp[i]=inf;
		REP(j,min(d+1,i+1)){
			if(s[i-j]=='0')continue;
			dp[i]=min(dp[i],1+dp[i-j]);
		}
	}
	if(dp[n-1]==inf)cout<<-1;
	else cout<<dp[n-1];
}