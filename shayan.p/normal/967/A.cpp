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

bool mark[2000];
ll n,s;

bool check(ll t){
	FOR(i,(t-s),(t+s)){
		if(i<0)
			continue;
		if(mark[i])
			return 0;
	}
	return 1;
}

int main(){
	cin>>n>>s;
	REP(i,n){
		ll h,m;cin>>h>>m;
		ll t=60*h+m;
		mark[t]=1;
	}
	REP(i,2000){
		if(check(i)){
			cout<<(i/60)<<" "<<(i%60);
			return 0;
		}
	}
}