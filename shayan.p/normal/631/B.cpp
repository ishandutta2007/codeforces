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
const ll maxn=5e3+10;

pll r[maxn],c[maxn];

int main(){
	ll n,m,k;cin>>n>>m>>k;
	REP(i,k){
		ll t,X,A;cin>>t>>X>>A;
		if(t==1){
			r[X-1]=MP(A,i);
		}
		else{
			c[X-1]=MP(A,i);
		}
	}
	REP(i,n){
		REP(j,m){
			ll num=0;
			if(r[i]!=MP(ll(0),ll(0))&&c[j]!=MP(ll(0),ll(0))){
				if(r[i].S>c[j].S)cout<<r[i].F<<" ";
				else cout<<c[j].F<<" ";
			}
			else if(r[i]!=MP(ll(0),ll(0))){
				cout<<r[i].F<<" ";
			}
			else if(c[j]!=MP(ll(0),ll(0))){
				cout<<c[j].F<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
}