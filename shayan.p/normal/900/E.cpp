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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;

pll dp[maxn];//maximum acuarance of t // minimum numer of ? we should change to reach it
ll sum[maxn];

int main(){
	ll n,m;
	string s;
	cin>>n>>s>>m;
	
	ll lsta[2],lstb[2];
	fill(lsta,lsta+2,n);
	fill(lstb,lstb+2,n);
	
	sum[0]=(s[0]=='?');
	FOR(i,1,n-1)
		sum[i]=(s[i]=='?')+sum[i-1];
		
	FORD(i,n-1,0){
		if(s[i]=='b'){
			dp[i]=dp[i+1];
			lstb[i%2]=i;
			continue;
		}
		ll lst=min(lsta[(i+1)%2],lstb[i%2])-1;
		if(i+m-1>lst){
			if(s[i]=='a')
				lsta[i%2]=i;
			dp[i]=dp[i+1];
			continue;
		}
		pll A,B;//choices
		A=dp[i+1];
		B.F=-(-dp[i+m].F+1);// we will make it negative in order to work with min correctly
		B.S=sum[i+m-1]-(i==0?0:sum[i-1])+dp[i+m].S;
		dp[i]=min(A,B);
		if(s[i]=='a')lsta[i%2]=i;
	}
	cout<<dp[0].S;
}