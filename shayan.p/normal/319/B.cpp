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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn],dp[maxn];
stack<ll>s;

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	a[n]=inf;
	s.push(n);
	
	REPD(i,n){
		while(a[s.top()]<a[i]){
			if(dp[s.top()]<=dp[i])
				dp[i]++;
			else
				dp[i]=dp[s.top()];
			s.pop();
		}
		s.push(i);
	}
	ll ans=0;
	while(sz(s)){
		ans=max(ans,dp[s.top()]);
		s.pop();
	}
	cout<<ans;
}