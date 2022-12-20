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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;

ll a[maxn],dp[maxn],sm[maxn];
deque<ll>d;

void Push(ll ind){
	while(sz(d)&&a[d.back()]>=a[ind])
		d.POB();
	d.PB(ind);
}
ll Min(ll ind){
	while(sz(d)&&d.front()<ind)
		d.POF();
	return a[d.front()];
}
int main(){
	ll n,c;cin>>n>>c;
	FOR(i,1,n){
		cin>>a[i];
		sm[i]=sm[i-1]+a[i];
	}
	if(c>n){
		ll sm=0;
		FOR(i,1,n)
			sm+=a[i];
		cout<<sm;
		return 0;
	}
	FOR(i,1,c-1){
		Push(i);
		dp[i]=dp[i-1]+a[i];
	}
	FOR(i,c,n){
		Push(i);
		dp[i]=min(a[i]+dp[i-1],sm[i]-sm[i-c]+dp[i-c]-Min(i-c+1));
	}
	cout<<dp[n];
}