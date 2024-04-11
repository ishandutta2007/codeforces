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

ll n,x;

ll check(ll num,ll pos){
	ll a[3];
	memset(a,0,sizeof a);
	a[pos]=1;
	REP(i,num){
		if(i%2)
			swap(a[1],a[2]);
		else
			swap(a[0],a[1]);
	}
	REP(i,3)
		if(a[i]==1)
			return i;
}

int main(){
	cin>>n>>x;
	n%=6;
	if(check(n,0)==x)
		cout<<0;
	if(check(n,1)==x)
		cout<<1;
	if(check(n,2)==x)
		cout<<2;
}