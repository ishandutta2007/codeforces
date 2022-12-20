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
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];

int main(){
	ll n,k;cin>>n>>k;
	ll mx=0,mxid=0;
	REP(i,k){
		cin>>a[i];
		ll num=n-(n%a[i]);
		if(num>mx){
			mx=num;
			mxid=i;
		}
	}
	cout<<mxid+1<<" "<<(n/a[mxid])<<endl;
}