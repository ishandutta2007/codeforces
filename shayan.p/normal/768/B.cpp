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

const ll inf=4e18;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

map<ll,ll>SZ;

ll find_SZ(ll x){
	if(x<=1){
		SZ[1]=1;
		return 1;
	}
	ll num=find_SZ(x/2);
	SZ[x]=(num*2)+1;
	return SZ[x];
}

ll seg(ll x,ll l,ll r){
	ll pos=SZ[x/2]+1;
	if(l<pos&&r<pos){
		return seg(x/2,l,r);
	}
	if(pos<l&&pos<r){
		return seg(x/2,l-pos,r-pos);
	}
	if(l==pos&&r==pos){
		return (x%2);
	}
	if(l==pos){
		return (x%2)+seg(x/2,1,r-pos);
	}
	if(r==pos){
		return (x%2)+seg(x/2,l,r-1);
	}
	return seg(x/2,l,SZ[x/2])+(x%2)+seg(x/2,1,r-pos);
}

int main(){
	ll n,l,r;cin>>n>>l>>r;
	find_SZ(n);
	cout<<seg(n,l,r);
}