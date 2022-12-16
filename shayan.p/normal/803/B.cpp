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
const ll maxn=2e5+10;
const ll mod=1e9+7;

int main(){
	ll n;cin>>n;
	vector<ll>v;
	REP(i,n){
		ll x;cin>>x;
		if(x==0)
			v.PB(i);
	}
	ll now=0;
	REP(i,n){
		ll a=inf,b=inf;
		if(i==v[now]){
			cout<<0<<" ";
			now++;
			continue;
		}
		if(now!=0){
			a=i-v[now-1];
		}
		if(now!=sz(v)){
			b=v[now]-i;
		}
		cout<<min(a,b)<<" ";
	}
}