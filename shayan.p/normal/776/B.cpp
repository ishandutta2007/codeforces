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
const ll maxn=1e5+10;

#pragma GCC Optimize("Ofast")

bool prime[maxn];

int main(){
	for(ll i=2;i<maxn;i++){
		if(!prime[i])
			for(ll j=i*i;j<maxn;j+=i)
				prime[j]=1;
	}
	ll n;cin>>n;
	if(n<3){
		cout<<1<<endl;
		REP(i,n)
			cout<<1<<" ";
		return 0;
	}
	cout<<2<<endl;
	FOR(i,2,n+1)
		if(prime[i])
			cout<<2<<" ";
		else
			cout<<1<<" ";
}