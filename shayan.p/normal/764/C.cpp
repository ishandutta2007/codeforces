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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;

#pragma GCC Optimize("Ofast")

ll c[maxn];
pll e[maxn];

int main(){
	ll n;scanf("%d",&n);
	REP(i,n-1)
		scanf("%d%d",&e[i].F,&e[i].S);
	FOR(i,1,n)
		scanf("%d",&c[i]);
		
	vector<pll>v;
	REP(i,n-1)
		if(c[e[i].F]!=c[e[i].S])
			v.PB(e[i]);
	if(sz(v)==0){
		cout<<"YES\n"<<1;
		return 0;
	}
	set<ll>dom;
	dom.insert(v[0].F);
	dom.insert(v[0].S);
	FOR(i,1,sz(v)-1){
		if(!dom.count(v[i].F)&&!dom.count(v[i].S)){
			cout<<"NO";
			return 0;
		}
		if(dom.count(v[i].F)){
			dom.clear();
			dom.insert(v[i].F);
		}
		if(dom.count(v[i].S)){
			dom.clear();
			dom.insert(v[i].S);
		}
	}
	cout<<"YES\n"<<*dom.begin();
}