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
const ll maxn=1e5+10;

vector<ll>v;
int main(){
	ll n,k;cin>>n>>k;
	ll sq=sqrt(n);
	for(ll i=1;i<=sq;i++)
		if(n%i==0)
			v.PB(i);
	ll Sz=sz(v);
	if(sq*sq==n){
		REPD(i,Sz-1)
			v.PB(n/v[i]);
	}
	else{
		REPD(i,Sz)
			v.PB(n/v[i]);
	}
	if(sz(v)<k)
		cout<<-1;
	else
		cout<<v[k-1];
}