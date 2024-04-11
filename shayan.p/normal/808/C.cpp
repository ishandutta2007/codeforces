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
const ll maxn=110;//

pll p[maxn];
ll ans[maxn];

int main(){
	ll n,w;cin>>n>>w;
	REP(i,n){
		cin>>p[i].F;
		p[i].S=i;
	}
	sort(p,p+n,greater<pll>());
	REP(i,n){
		ll m=(p[i].F/2)+(p[i].F%2);
		ans[p[i].S]=m;
		w-=m;
		if(w<0){
			cout<<-1;//
			return 0;
		}
	}
	REP(i,n){
		ll m=min(p[i].F-ans[p[i].S],w);
		w-=m;
		ans[p[i].S]+=m;
	}
	REP(i,n){
		cout<<ans[i]<<" ";
	}
}