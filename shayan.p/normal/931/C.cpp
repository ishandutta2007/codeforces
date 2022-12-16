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
const ll mod=1e9+7;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

map<ll,ll>mp;
vector<pll>v;

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		mp[x]++;
	}
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
		v.PB(*it);
	if((sz(v)==1)||(sz(v)==2&&v[1].F-v[0].F==1)){
		cout<<n<<endl;
		REP(i,sz(v))
			REP(j,v[i].S)
				cout<<v[i].F<<" ";
		return 0;
	}
	if(sz(v)==2){// alan ektelaf 2 has
		ll B=min(v[0].S,v[1].S);
		ll A=v[0].S-B;
		ll C=v[1].S-B;
		B*=2;
		cout<<(n-B)<<endl;
		REP(i,A)
			cout<<v[0].F<<" ";
		REP(i,B)
			cout<<v[0].F+1<<" ";
		REP(i,C)
			cout<<v[1].F<<" ";
		return 0;	
	}
	ll SUM=v[2].S-v[0].S;
	ll A=v[0].S,B=v[1].S,C=v[2].S,ans=n;
	FOR(i,0,n){
		if((-(n-i))<=SUM&&SUM<=(n-i)){
			ll mosb=(n-i+SUM)/2;
			ll manf=n-i-mosb;
			if((mosb-manf)!=SUM||mosb<0||manf<0)
				continue;
			ll num=min(manf,v[0].S)+min(i,v[1].S)+min(mosb,v[2].S);
			if(num<ans){
				A=manf;
				B=i;
				C=mosb;
				ans=num;
			}
		}
	}
	cout<<ans<<endl;
	REP(i,A)
		cout<<v[0].F<<" ";
	REP(i,B)
		cout<<v[1].F<<" ";
	REP(i,C)
		cout<<v[2].F<<" ";
}