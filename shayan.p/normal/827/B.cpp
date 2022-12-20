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
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

int main(){
	ll n,k;cin>>n>>k;
	ll num=n-1;
	ll l1=num/k;ll l2=l1+(num%k!=0);
	ll t2=num-(k*l1);ll t1=k-t2;
	ll dis=(t2>1?l2+l2:l1+l2);
	cout<<dis<<endl;
	ll lst,nw=2;
	REP(i,t1){
		lst=1;
		REP(j,l1){
			cout<<lst<<" "<<nw<<endl;
			lst=nw++;
		}
	}
	REP(i,t2){
		lst=1;
		REP(j,l2){
			cout<<lst<<" "<<nw<<endl;
			lst=nw++;
		}
	}
}