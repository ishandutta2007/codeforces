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
const ll maxn=1e5+10;

ll a[maxn],b[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i]>>b[i];
	REP(i,n){
		if(a[i]!=b[i]){
			cout<<"rated";
			return 0;
		}
	}
	FOR(i,1,n-1){
		if(a[i]>a[i-1]){
			cout<<"unrated";
			return 0;
		}
	}
	cout<<"maybe";
}