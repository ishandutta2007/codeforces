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

map<ll,set<ll> > mp;
vector<pll>ans;

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		while(mp.count(x)){
			ll pt=*mp[x].begin();
			mp[x].erase(pt);
			if(mp[x].empty())
				mp.erase(x);
			x*=2;
		}
		mp[x].insert(i);
	}
	for(map<ll,set<ll> >::iterator it1=mp.begin();it1!=mp.end();it1++){
		set<ll>&st=it1->S;
		ll num=it1->F;
		for(set<ll>::iterator it2=st.begin();it2!=st.end();it2++){
			ans.PB(MP((*it2),num));
		}
	}
	sort(ans.begin(),ans.end());
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<ans[i].S<<" ";
}