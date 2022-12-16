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

int main(){
	ll h1,h2,a,b;cin>>h1>>h2>>a>>b;
	ll h=h2-h1;
	h-=8*a;
	ll day=0;
	REP(i,maxn){
		if(h<=0){
			cout<<day;
			return 0;
		}
		h+=12*b;
		h-=12*a;
		day++;
	}
	cout<<-1;
}