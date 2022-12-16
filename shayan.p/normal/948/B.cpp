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

const ll inf=1e18;
const ll maxn=1e6+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>p,pos;
ll par[maxn];
ll is[maxn];// 1 if composite

void tajzie(ll num){
	p.clear();
	while(num>1){
		p.PB(par[num]);
		ll pp=par[num];
		while(num%pp==0)
			num/=pp;
	}
}

int main(){
	for(ll i=2;i<maxn;i++){
		if(!is[i]){
			par[i]=i;
			for(ll j=2*i;j<maxn;j+=i){
				par[j]=i;
				is[j]=1;
			}
		}
	}
	ll x;cin>>x;
	tajzie(x);
	REP(i,sz(p)){
		REP(j,p[i]){
			pos.PB(x-j);
		}
	}
	ll ans=inf;
	REP(i,sz(pos)){
		if(!is[pos[i]])continue;
		tajzie(pos[i]);
		ll mx=1;
		REP(j,sz(p))
			mx=max(mx,p[j]);
		ans=min(ans,pos[i]-mx+1);
	}
	cout<<ans;
}