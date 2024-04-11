// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

set<ll>exis,nzero;
ll num[20];
pll p[20];
int main(){
	ll n;cin>>n;
	REP(i,n){
		string s;cin>>s;
		nzero.insert(s[0]-'a');
		ll ten=1;
		REPD(j,s.size()){
			num[s[j]-'a']+=ten;
			ten*=10;
		}
	}
	REP(i,10){
		p[i]=MP(num[i],i);
	}
	sort(p,p+10,greater<pll>());
	REP(i,10){
		exis.insert(i);
	}
	ll ans=0;
	REP(i,10){
		if(exis.count(0)&&!nzero.count(p[i].S)){
			exis.erase(0);
			continue;
		}
		FOR(j,1,9){
			if(exis.count(j)){
				ans+=j*p[i].F;
				exis.erase(j);
				break;
			}
		}
	}
	cout<<ans;
}