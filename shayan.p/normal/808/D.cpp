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

#pragma GCC optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll inf=1e18;
const ll maxn=1e5+10;

ll a[maxn],tot;
int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
		tot+=a[i];
	}
	if(tot%2){
		cout<<"NO";
		return 0;
	}
	ll half=tot/2;
	set<ll>s;
	ll sum=0;
	REP(i,n){
		sum+=a[i];
		s.insert(a[i]);
		ll num=(sum-half);
		if(s.count(num)){
			cout<<"YES";
			return 0;
		}
	}
	sum=0;
	s.clear();
	REPD(i,n){
		sum+=a[i];
		s.insert(a[i]);
		ll num=(sum-half);
		if(s.count(num)){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}