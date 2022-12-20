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

set<ll>no;

int main(){
	ll b,q,l,m;cin>>b>>q>>l>>m;
	REP(i,m){
		ll x;cin>>x;
		no.insert(x);
	}
	if(abs(b)>l){
		cout<<0;
		return 0;
	}
	if(b==0){
		if(no.count(0))
			cout<<0;
		else
			cout<<"inf";
		return 0;
	}
	if(q==1){
		if(no.count(b))
			cout<<0;
		else
			cout<<"inf";
		return 0;
	}
	if(q==-1){
		if(no.count(b)&&no.count(-b))	
			cout<<0;
		else
			cout<<"inf";
		return 0;
	}
	if(q==0){
		if(no.count(0))
			cout<<!no.count(b);
		else
			cout<<"inf";
		return 0;
	}
	ll ans=0;
	while(abs(b)<=l){
		ans+=(!no.count(b));
		b*=q;
	}
	cout<<ans;
	return 0;
}