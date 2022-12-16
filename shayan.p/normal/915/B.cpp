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
const ll mod=1e9+7;
const ll maxn=2e5+10;

int main(){
	ll n,pos,l,r;cin>>n>>pos>>l>>r;
	ll ans=0;
	if(pos<l){
		ans+=(l-pos);
		pos=l;
	}
	if(pos>r){
		ans+=(pos-r);
		pos=r;
	}
	if(l==1&&r==n){
		cout<<0;
		return 0;
	}
	if(l==1){
		ans+=abs(r-pos);
		cout<<ans+1;
		return 0;
	}
	if(r==n){
		ans+=abs(pos-l);
		cout<<ans+1;
		return 0;
	}
	ans+=(r-l)+min(abs(r-pos),abs(l-pos));
	cout<<ans+2;
	return 0;
}