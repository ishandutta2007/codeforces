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
typedef pair<pll,ll> pl3;

const ll inf=4e18;
const ll maxn=1e5+10;

#pragma GCC Optimize("Ofast")

ll tree[3*maxn];
ll	ask(ll ind){
	ll ans=0;
	while(ind>0){
		ans=max(ans,tree[ind]);
		ind-=(ind & -ind);
	}
	return ans;
}
void add(ll ind,ll num){
	while(ind<(3*maxn)){
		tree[ind]=max(tree[ind],num);
		ind+=(ind & -ind);
	}
}

pl3 w[maxn];// out in h

int main(){
	ll n;cin>>n;
	set<ll>s;
	map<ll,ll>mp;
	REP(i,n){
		cin>>w[i].F.S>>w[i].F.F>>w[i].S;
		s.insert(w[i].F.S);
		s.insert(w[i].F.F);
	}
	ll h=1;
	for(set<ll>::iterator it=s.begin();it!=s.end();it++){
		mp[*it]=h++;
	}
	REP(i,n){
		w[i].F.S=mp[w[i].F.S];
		w[i].F.F=mp[w[i].F.F];
	}
	
	sort(w,w+n,greater<pl3>());
	ll ans=0;
	REP(i,n){
		ll num=ask(w[i].F.F-1)+w[i].S;
		ans=max(num,ans);
		add(w[i].F.S,num);
	}
	cout<<ans;
}