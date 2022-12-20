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
ll n;
vector<ll>v[4*maxn];

ll binary(vector<ll>&vec,ll x){
	ll l=0,r=sz(vec)-1,id=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(x<=vec[mid]){
			id=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return id+1;
}

ll ask(ll f,ll s,ll x,ll l=1,ll r=n,ll id=1){
	if(l>r)return 0;
	if(f>r||s<l)return 0;
	if(f<=l&&r<=s)
		return binary(v[id],x);
	ll mid=(l+r)/2;
	return ask(f,s,x,l,mid,2*id)+ask(f,s,x,mid+1,r,2*id+1);
}

void merge(vector<ll>&a,vector<ll>&b,vector<ll>&c){
	ll pb=0,pc=0;
	while((pb+pc)<(sz(b)+sz(c))){
		if(pb==sz(b)){
			a.PB(c[pc++]);
		}
		else if(pc==sz(c)){
			a.PB(b[pb++]);
		}
		else{
			if(b[pb]>c[pc]){
				a.PB(b[pb++]);
			}
			else{
				a.PB(c[pc++]);
			}
		}
	}
}

void build(ll l=1,ll r=n,ll id=1){
	if(l==r){
		v[id].PB(a[l]);
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*id);
	build(mid+1,r,2*id+1);
	merge(v[id],v[2*id],v[2*id+1]);
}

int main(){
	cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	build();
	ll ans=0;
	FOR(i,1,n){
		ans+=ask(i,min(a[i],n),i);
		ans-=(i<=a[i]);
	}
	cout<<ans;
}