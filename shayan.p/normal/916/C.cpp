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

#pragma GCC Optimize("Ofast")

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll p=999563;

int main(){
	ll n,m;cin>>n>>m;
	if(n==2&&m==1){
		cout<<p<<" "<<p<<endl;
		cout<<1<<" "<<2<<" "<<p<<endl;
		return 0;
	}
	ll sm=0;
	cout<<2<<" "<<p<<endl;
	FOR(i,3,n){
		sm+=2;
		cout<<1<<" "<<i<<" "<<2<<endl;
	}
	ll ed=p-sm;
	cout<<1<<" "<<2<<" "<<ed<<endl;
	ed++;
	m-=(n-1);
	FOR(i,2,n){
		FOR(j,i+1,n){
			if(m==0)
				return 0;
			m--;
			cout<<i<<" "<<j<<" "<<ed<<endl;
		}
	}
}