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

#pragma GCC Optimize("Ofast")


ll phi(ll num){
	if(num==1)
		return 0;
	ll p=1,q=1,cop=num;
	for(ll i=2;(i*i)<=num;i++){
		if(num%i==0){
			while(num%i==0)
				num/=i;
			p*=(i-1);
			q*=i;
		}
	}
	if(num>1){
		p*=(num-1);
		q*=num;
	}
	
	cop/=q;
	cop*=p;
	return cop;
}

int main(){
	ll n,k;cin>>n>>k;
	k=(k+1)/2;
	REP(i,k){
		if(n==1){
			cout<<1;
			return 0;
		}
		n=phi(n);
	}
	cout<<n%mod;
}