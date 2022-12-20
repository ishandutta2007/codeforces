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
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll a[20],b[20];

ll check(ll id){
	REP(i,14)
		b[i]=a[i];
	ll num=b[id];
	b[id]=0;
	REP(i,14)
		b[i]+=(num/14);
	num=num%14;
	REP(i,num)
		b[(i+id+1)%14]++;
	ll x=0;
	REP(i,14)
		x+=(!(b[i]%2))*b[i];
	return x;
}

int main(){
	REP(i,14)
		cin>>a[i];
	ll ans=0;
	REP(i,14)
		ans=max(ans,check(i));
	cout<<ans;
}