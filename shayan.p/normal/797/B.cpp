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
const ll maxn=2e5+10;

int main(){
	ll z=0;
	vector<ll>f;
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		if(x%2==0){
			if(x>0)
				z+=x;
		}
		else{
			f.PB(x);
		}
	}
	sort(f.begin(),f.end(),greater<ll>());
	ll mx=f[0],sum=f[0];
	for(ll i=2;i<sz(f);i+=2){
		sum+=f[i]+f[i-1];
		mx=max(mx,sum);
	}
	cout<<mx+z;
}