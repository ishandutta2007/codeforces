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

const ll inf=1e18+1;
const ll maxn=2e5+10;

bool over_flow(ll a,ll b){
	if(a>(inf/b))return 1;
	return 0;
}
vector<ll>v;
int main(){
	ll x,y,l,r;cin>>x>>y>>l>>r;
	for(ll x1=1;;x1*=x){
		for(ll y1=1;;y1*=y){
			if(l<=x1+y1&&x1+y1<=r)
				v.PB(x1+y1);
			if(over_flow(y1,y)){
				break;
			}
		}
		if(over_flow(x1,x)){
			break;
		}
	}
	v.PB(l-1);
	v.PB(r+1);
	ll ans=0;
	sort(v.begin(),v.end());
	FOR(i,1,sz(v)-1){
		ans=max(ans,v[i]-v[i-1]-1);
	}
	cout<<ans;
}