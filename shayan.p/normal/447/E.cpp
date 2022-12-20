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

const ll maxn=3e5+10;
const ll mod=1e9+9;

ll fib[maxn],sum_one[maxn],sum_two[maxn],asar_one[maxn],asar_two[maxn];

inline ll find_fib(pll p,ll t){// age jomle 0 p.F bashe va jomle 1 p.S bashe -> jomle t chie?
	return ((asar_one[t]*p.F)+(asar_two[t]*p.S))%mod;
}

inline ll find_sum_fib(pll p,ll t){
	return ((sum_one[t]*p.F)+(sum_two[t]*p.S))%mod;
}

// segment part
pll lazy[4*maxn];
ll val[4*maxn],n;

void get(ll l,ll r,ll ind){
	if(lazy[ind].F==0&&lazy[ind].S==0)return;
	val[ind]=(val[ind]+find_sum_fib(lazy[ind],r-l))%mod;
	if(l!=r){
		ll mid=(l+r)/2;
		lazy[2*ind].F+=lazy[ind].F;
		lazy[2*ind].S+=lazy[ind].S;
		lazy[2*ind+1].F+=find_fib(lazy[ind],mid-l+1);
		lazy[2*ind+1].S+=find_fib(lazy[ind],mid-l+2);
		lazy[2*ind].F%=mod;
		lazy[2*ind].S%=mod;
		lazy[2*ind+1].F%=mod;
		lazy[2*ind+1].S%=mod;
	}
	lazy[ind]=MP(0,0);
}

ll ask(ll targl,ll targr,ll ind=1,ll l=0,ll r=maxn){
	if(l>r)return 0;
	get(l,r,ind);
	if(targr<l||r<targl)return 0;
	if(targl<=l&&r<=targr)return val[ind];
	ll mid=(l+r)/2,value=0;
	return (ask(targl,targr,2*ind,l,mid)+ask(targl,targr,2*ind+1,mid+1,r))%mod;
}

void add(ll targ,ll value,ll ind=1,ll l=0,ll r=maxn){
	if(l>r)return;
	if(targ<l||r<targ)return;
	val[ind]+=value;
	val[ind]%=mod;
	ll mid=(l+r)/2;
	if(l!=r){
		add(targ,value,2*ind,l,mid);
		add(targ,value,2*ind+1,mid+1,r);
	}
}

void add_lazy(ll targl,ll targr,ll ind=1,ll l=0,ll r=maxn){
	if(l>r)return;
	get(l,r,ind);
	if(targr<l||r<targl) return;
	if(targl<=l&&r<=targr){
		lazy[ind].F=(lazy[ind].F+fib[l-targl])%mod;
		lazy[ind].S=(lazy[ind].S+fib[l-targl+1])%mod;
		get(l,r,ind);
		return;
	}
	ll mid=(l+r)/2;
	add_lazy(targl,targr,2*ind,l,mid);
	add_lazy(targl,targr,2*ind+1,mid+1,r);
	val[ind]=(val[2*ind]+val[2*ind+1])%mod;
}

void pre_com(){
	fib[0]=1;fib[1]=1;
	FOR(i,2,maxn-1)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	sum_one[0]=1;
	sum_one[1]=1;
	FOR(i,2,maxn-1)
		sum_one[i]=(fib[i-2]+sum_one[i-1])%mod;
	sum_two[0]=0;
	FOR(i,1,maxn-1)
		sum_two[i]=(sum_two[i-1]+fib[i-1])%mod;
	asar_one[0]=1;
	asar_one[1]=0;
	FOR(i,2,maxn-1)
		asar_one[i]=fib[i-2];
	asar_two[0]=0;
	FOR(i,1,maxn-1)
		asar_two[i]=fib[i-1];
}

int main(){
	pre_com();
	ll m;cin>>n>>m;
	REP(i,n){
		ll x;cin>>x;
		add(i,x);
	}
	REP(i,m){
		ll act,l,r;cin>>act>>l>>r;
		l--;r--;
		if(act==1)
			add_lazy(l,r);
		else
			cout<<ask(l,r)<<endl;
	}
}