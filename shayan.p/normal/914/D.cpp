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
typedef int ll;/////////////////curfull
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> pl3;

const ll mod=1e9+7;
const ll maxn=5e5+10;

// 1 based
ll val[4*maxn];
ll a[maxn];
ll n;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void build(ll l=1,ll r=n,ll ind=1){
	if(l==r){
		val[ind]=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	val[ind]=gcd(val[2*ind],val[2*ind+1]);
}

void add(ll targ,ll x,ll l=1,ll r=n,ll ind=1){
	if(l>r)return;
	if(targ<l||r<targ)return;
	if(l==r){
		val[ind]=x;
		return;
	}
	ll mid=(l+r)/2;
	add(targ,x,l,mid,2*ind);
	add(targ,x,mid+1,r,2*ind+1);
	val[ind]=gcd(val[2*ind],val[2*ind+1]);
}

pair<ll,pl3> seg;

void decompos(ll f,ll s,ll x,ll l=1,ll r=n,ll ind=1){
	if(l>r)return;
	if(r<f||s<l)return;
	if(f<=l&&r<=s){
		if(val[ind]%x!=0){
			seg.F++;
			seg.S.F=ind;
			seg.S.S.F=l;
			seg.S.S.S=r;
		}
		return;
	}
	ll mid=(l+r)/2;
	decompos(f,s,x,l,mid,2*ind);
	decompos(f,s,x,mid+1,r,2*ind+1);
}

bool check(ll ind,ll l,ll r,ll x){
	if(l==r)return 1;
	ll mid=(l+r)/2;
	if(val[2*ind]%x!=0&&val[2*ind+1]%x!=0)return 0;
	if(val[2*ind]%x==0&&val[2*ind+1]%x==0)return 1;
	if(val[2*ind]%x!=0&&val[2*ind+1]%x==0)return check(2*ind,l,mid,x);
	if(val[2*ind]%x==0&&val[2*ind+1]%x!=0)return check(2*ind+1,mid+1,r,x);
}

bool ask(ll f,ll s,ll x){
	seg=MP(0,MP(-1,MP(-1,-1)));// number // ind//  l // r
	decompos(f,s,x);
	if(seg.F==0)return 1;
	if(seg.F>1)return 0;
	return check(seg.S.F,seg.S.S.F,seg.S.S.S,x);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n)
		scanf("%d",&a[i]);
	build();
	ll q;scanf("%d",&q);
	while(q--){
		ll task;scanf("%d",&task);
		if(task==1){
			ll l,r,x;scanf("%d%d%d",&l,&r,&x);
			if(ask(l,r,x))printf("YES\n");
			else printf("NO\n");
		}
		else{
			ll ind,y;scanf("%d%d",&ind,&y);
			add(ind,y);
		}
	}
}