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

const ll maxn=2e5+10;

bool good(ll num){
	bool b1=((num%10)==7);
	num/=10;
	bool b2=((num%10)==7);
	return b1|b2;
}

int main(){
	ll x;cin>>x;
	ll a,b;cin>>a>>b;
	ll ans=0;
	while(!good(a)&&!good(b)){
		ans++;
		b-=x;
		if(b<0){
			b=60+b;
			a--;
			if(a<0)
				a=23;
		}
	}
	cout<<ans;
}