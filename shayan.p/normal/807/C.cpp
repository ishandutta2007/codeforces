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

const ll BIG=1e9+10;

int main(){
	ll t;cin>>t;
	REP(i,t){
		ll x,y,p,q;cin>>x>>y>>p>>q;
		if(p==1&&q==1){
			if(x==y)
				cout<<0;
			else
				cout<<-1;
			cout<<endl;
			continue;
		}
		if(p==0){
			if(x==0)
				cout<<0;
			else
				cout<<-1;
			cout<<endl;
			continue;
		}
		ll ff=(x/p)+((x%p)!=0);
		ll ss=(y/q)+((y%q)!=0);
		ll num=max(ff,ss);
		ll l=num,r=BIG,ans=-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if((mid*q-y)>=(mid*p-x)){
				ans=(mid*q-y);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}