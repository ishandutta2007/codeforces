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

map<pll,ll>mp;
ll calc(ll x,ll mask){// if i th bit is 0 we can gather i+1 numbers
	if(mp.count(MP(x,mask)))
		return mp[MP(x,mask)];
	bool is[61];
	memset(is,0,sizeof is);
	
	REP(i,60){
		if(x-i-1>=0&&bit(mask,i)==0)
			is[calc(x-i-1,mask^(1<<i))]=1;
	}
	ll now=0;
	REP(i,60){
		if(!is[i]){
			mp[MP(x,mask)]=i;
			return i;
		}
	}
}

int main(){
	ll n;cin>>n;
	ll XOR=0;
	REP(i,n){
		ll x;cin>>x;
		XOR^=calc(x,0);
	}
	if(XOR==0)
		cout<<"YES";
	else
		cout<<"NO";
}