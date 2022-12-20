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

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;

#pragma GCC Optimize("Ofast")

ll a[maxn];

void shift(ll &a,ll &b,ll &c,ll &d){
	ll e=d;
	d=c;
	c=b;
	b=a;
	a=e;
}
int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		a[i]=i;
	if(n%4==1||n%4==0){
		FOR(i,1,n/4){
			ll nw=i*2-1;
			shift(a[nw],a[nw+1],a[n+1-nw],a[n-nw]);
		}
		FOR(i,1,n)
			cout<<a[i]<<" ";
	}
	else
		cout<<-1;
}