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
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

struct child{
	ll id,V,D,P;
	void get(ll x){
		id=x;
		cin>>V>>D>>P;
	}
};
vector<child>v[2];
vector<ll>ans;

int main(){
	ll n;cin>>n;
	REP(i,n){
		child ch;
		ch.get(i);
		v[0].PB(ch);
	}
	ll o=0;
	while(sz(v[o])>0){
		v[1-o].clear();
		ans.PB(v[o][0].id);
		ll c=v[o][0].V;
		ll sm=0;
		if(sz(v[o])==1)
			break;
		FOR(i,1,sz(v[o])-1){// FOR 1 ,0 bug?
			ll les=sm+max(c-i+1,ll(0));
			v[o][i].P-=les;
			if(v[o][i].P>=0){
				v[1-o].PB(v[o][i]);
			}
			else{
				sm+=v[o][i].D;
			}
		}
		o=1-o;
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<ans[i]+1<<" ";
}