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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn],b[maxn],mx[maxn],mxind;

int main(){
	ll n;cin>>n;
	a[0]=-1;
	FOR(i,1,n){
		cin>>a[i];
		if(a[mxind]<a[i])
			mxind=i;
		mx[i]=max(mx[i-1],a[i]);
	}
	FOR(i,mxind,n)
		b[i]=a[mxind];
	FORD(i,mxind-1,1){
		if(b[i+1]==mx[i])
			b[i]=b[i+1];
		else
			b[i]=b[i+1]-1;
	}
	ll ans=0;
	FOR(i,1,n)
		ans+=b[i];
	FOR(i,1,n)
		ans-=a[i];
	cout<<ans;
}