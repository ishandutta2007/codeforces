// new day,new strength,new thougts

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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=60;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

bool dp[maxn][maxn];// book // shelf
ll a[maxn];
ll tw[maxn];
vector<ll>bt;

bool OK(ll num){
	REP(i,sz(bt)){
		if(!bit(num,bt[i]))
			return 0;
	}
	return 1;
}

int main(){
	ll n,k;cin>>n>>k;
	FOR(i,1,n)
		cin>>a[i];
		
	REPD(q,59){
		// bit i om mishe 1 bashe?
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		bt.PB(q);
		FOR(j,1,k){
			FOR(i,1,n){
				ll sm=0;
				FORD(w,i,1){
					sm+=a[w];
					dp[i][j]|=(dp[w-1][j-1]&&OK(sm));
				}
			}
		}
		if(!dp[n][k])
			bt.POB();
	}
	
	tw[0]=1;
	FOR(i,1,maxn-1)
		tw[i]=2*tw[i-1];
	ll ans=0;
	REP(i,sz(bt)){
		ans+=tw[bt[i]];
	}
	cout<<ans;
}