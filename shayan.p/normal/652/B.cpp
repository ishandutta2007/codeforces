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

ll a[maxn];

int main(){
	ll n;cin>>n;
	multiset<ll>s;
	REP(i,n)
		cin>>a[i];
	sort(a,a+n);
	ll h1=0,h2=n-1;
	REP(i,n){
		if(i%2)
			cout<<a[h2--];
		else
			cout<<a[h1++];
		cout<<" ";
	}
}