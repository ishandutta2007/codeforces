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

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;

vector<pair<ll,bool> > v;
int main(){
	ll a,b,both;cin>>a>>b>>both;
	ll m;cin>>m;
	REP(i,m){
		ll x;string s;
		cin>>x>>s;
		if(s=="USB")
			v.PB(MP(x,0));
		else
			v.PB(MP(x,1));
	}
	sort(v.begin(),v.end());
	ll ans=0,num=0;
	REP(i,sz(v)){
		if(v[i].S==0){
			ans+=v[i].F;
			if(a==0){
				if(both==0){
					ans-=v[i].F;
					num++;
				}
				else
					both--;
			}
			else
				a--;
		}
		if(v[i].S==1){
			ans+=v[i].F;
			if(b==0){
				if(both==0){
					ans-=v[i].F;
					num++;
				}
				else
					both--;
			}
			else
				b--;
		}
	}
	cout<<m-num<<" "<<ans;
}