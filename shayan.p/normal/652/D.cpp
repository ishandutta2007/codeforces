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

ll ans[maxn];
pair<pll,ll> p[maxn];
ll n;
ll tree[2*maxn];

void pre(){
	map<ll,ll>mp;
	vector<ll> vec;
	cin>>n;
	REP(i,n){
		cin>>p[i].F.F>>p[i].F.S;
		vec.PB(p[i].F.F);
		vec.PB(p[i].F.S);
		p[i].S=i;
	}
	sort(vec.begin(),vec.end());
	ll h=1;
	REP(i,sz(vec)){
		mp[vec[i]]=h++;
	}
	REP(i,n){
		p[i].F.F=mp[p[i].F.F];
		p[i].F.S=mp[p[i].F.S];
	}
	sort(p,p+n);
}

void add(ll ind,ll x){
	while(ind<2*maxn){
		tree[ind]+=x;
		ind+=(ind & -ind);
	}
}
ll ask(ll ind){
	ll ans=0;
	while(ind>0){
		ans+=tree[ind];
		ind-=(ind & -ind);
	}
	return ans;
}

int main(){
	pre();
	REPD(i,n){
		ans[p[i].S]=ask(p[i].F.S);
		add(p[i].F.S,1);
	}
	REP(i,n){
		cout<<ans[i]<<endl;
	}
}