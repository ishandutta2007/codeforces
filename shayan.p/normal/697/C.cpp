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

map<ll,ll>mp;

ll lg(ll num){
	ll ans=0;
	while(num>0){
		ans++;
		num/=2;
	}
	return ans;
}

int main(){
	ll q;cin>>q;
	REP(i,q){
		ll task,u,v,w;
		cin>>task>>u>>v;
		ll lgu=lg(u),lgv=lg(v);
		if(lgu>lgv){
			swap(lgu,lgv);
			swap(u,v);
		}
		stack<ll>s;
		REP(j,(lgv-lgu)){
			s.push(v);
			v/=2;
		}
		while(u!=v){
			s.push(u);
			s.push(v);
			u/=2;
			v/=2;
		}
		if(task==1){
			cin>>w;
			while(sz(s)){
				mp[s.top()]+=w;
				s.pop();
			}
		}
		else{
			ll ans=0;
			while(sz(s)){
				ans+=mp[s.top()];
				s.pop();
			}
			cout<<ans<<endl;
		}
	}
}