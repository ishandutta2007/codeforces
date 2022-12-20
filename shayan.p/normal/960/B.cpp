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
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];
priority_queue<ll>pq;

int main(){
	ll n,k1,k2,k;cin>>n>>k1>>k2;
	k=k1+k2;
	REP(i,n)
		cin>>a[i];
	REP(i,n){
		ll x;cin>>x;
		pq.push(abs(a[i]-x));
	}
	REP(i,k){
		ll num=pq.top();
		if(num==0){
			if((i%2)==(k%2))
				cout<<0;
			else
				cout<<1;
			return 0;
		}
		pq.pop();
		pq.push(num-1);
	}
	ll ans=0;
	while(sz(pq)){
		ll num=pq.top();
		ans+=(num*num);
		pq.pop();
	}
	cout<<ans;
}