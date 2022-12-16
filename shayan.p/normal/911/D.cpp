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

const ll inf=1e18;
const ll maxn=2010;
ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	ll num=0;
	FOR(i,0,n-1){
		FOR(j,i+1,n-1){
			if(a[i]>a[j])
			num++;
		}
	}
	bool b=num%2;
	ll m;cin>>m;
	REP(i,m){
		ll l,r;cin>>l>>r;
		ll len=r-l+1;
		ll num=((len)*(len-1))/2;
		if(num%2)b=!b;
		if(b)cout<<"odd\n";
		else cout<<"even\n";
	}
}