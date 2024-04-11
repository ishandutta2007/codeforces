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
const ll MAX=2e5+100;
const ll Big=2e6+10;

#pragma GCC Optimize("Ofast")

set<ll>pos;
set<ll>forb;
ll ans[maxn];
ll par[Big];
vector<ll>prim;
vector<ll>tot_pr;

void tajzie(ll num){
	prim.clear();
	while(num!=1){
		ll p=par[num];
		prim.PB(p);
		while(num%p==0)
			num/=p;
	}
}

int main(){
	FOR(i,2,(MAX-1))
		pos.insert(i);
	for(ll i=2;i<MAX;i++){
		if(par[i]==0){
			for(ll j=i;j<MAX;j+=i)
				par[j]=i;
		}
	}
	memset(par,0,sizeof par);
	for(ll i=2;i<Big;i++){
		if(par[i]==0){
			tot_pr.PB(i);
			for(ll j=i;j<Big;j+=i)
				par[j]=i;
		}
	}
	bool esc=0;
	ll pt=0;
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		if(esc){
			while(forb.count(tot_pr[pt]))
				pt++;
			ans[i]=tot_pr[pt++];
			continue;
		}
		ans[i]=(*pos.lower_bound(x));
		esc|=(ans[i]!=x);
		tajzie(ans[i]);
		REP(j,sz(prim)){
			if(!forb.count(prim[j])){
				forb.insert(prim[j]);
				for(ll k=prim[j];k<MAX;k+=prim[j])
					pos.erase(k);
			}
		}
	}
	REP(i,n)
		cout<<ans[i]<<" ";
}