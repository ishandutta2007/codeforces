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

pll a[maxn];
bool is[maxn];
ll lw[maxn],hg[maxn];
ll n;
map<ll,ll>mp;

void Delete(ll x){
	if(--mp[x]==0)mp.erase(x);
}

void Add(ll x){
	mp[x]++;
}

void Merge(ll u){
	is[u]=1;
	ll l,r;
	if(!is[u-1]&&!is[u+1]){
		Add(1);
		hg[u]=lw[u]=u;
	}
	if(is[u-1]&&!is[u+1]){
		l=lw[u-1];
		Delete(u-l);
		Add(u-l+1);
		hg[l]=u;
		lw[u]=l;
	}
	if(!is[u-1]&&is[u+1]){
		r=hg[u+1];
		Delete(r-u);
		Add(r-u+1);
		hg[u]=r;
		lw[r]=u;
	}
	if(is[u-1]&&is[u+1]){
		l=lw[u-1];
		r=hg[u+1];
		Delete(u-l);
		Delete(r-u);
		Add(r-l+1);
		lw[r]=l;
		hg[l]=r;
	}
}

int main(){
	cin>>n;
	FOR(i,1,n){
		cin>>a[i].F;
		a[i].S=i;
	}
	if(n==1){
		cout<<a[1].F+1;
		return 0;
	}
	sort(a+1,a+n+1);
	
	pll state=MP(0,1); // tedad jazire // k ke behesg beresim
	
	FOR(i,1,n){
		Merge(a[i].S);
		if(sz(mp)==1){
			ll num=(mp.begin()->S);
			if(state.F<num){
				state.F=num;
				state.S=a[i].F+1;
			}
		}
	}
	cout<<state.S;
}