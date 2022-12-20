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

#pragma GCC Optimize("Ofast")

ll s[maxn],lst[maxn],a[maxn],ans,lis[maxn][2],mx;

int main(){
	ll n,m;cin>>n>>m;
	REP(i,n){
		ll a,b;cin>>a>>b;
		s[b]++;
		s[a-1]--;
	}
	ll sm=0;
	FORD(i,m,1){
		sm+=s[i];
		a[i]=sm;
	}
	
	fill(lst+1,lst+maxn,inf);
	mx=0;
	FOR(i,1,m){
		ll up=upper_bound(lst,lst+maxn,a[i])-lst;
		lst[up]=a[i];
		mx=max(mx,up);
		lis[i][0]=mx;
	}
	fill(lst+1,lst+maxn,inf);
	mx=0;
	FORD(i,m,1){
		ll up=upper_bound(lst,lst+maxn,a[i])-lst;
		lst[up]=a[i];
		mx=max(mx,up);
		lis[i][1]=mx;
	}
	
	ans=max(lis[m][0],lis[1][1]);
	FOR(i,1,m-1)
		ans=max(ans,lis[i][0]+lis[i+1][1]);
	
	cout<<ans;
}