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
#define all(v) v.begin(),v.end()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#pragma GCC optimize("Ofast")

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const ll maxn=1e5+10;

pll a[15][maxn];
vpll vall[4*maxn],valr[4*maxn];
ll Sz[4*maxn];
ll n,m,q;
ll mrgz;
vector<ll> decompos;
map<pll,pll>par;

pll Find(pll a){
	if(!par.count(a))return a;
	return (par[a]=Find(par[a]));
}
void Merge(pll a,pll b){
	pll p1=Find(a),p2=Find(b);
	if(p1==p2)return;
	par[p1]=p2;
	mrgz++;
}
void merge(vpll &a,vpll &b,vpll &c,vpll &d){
	par.clear();
	REP(i,n){
		if(b[i].F==c[i].F){
			Merge(b[i],c[i]);
		}
	}
	REP(i,n){
		a[i]=Find(a[i]);
		b[i]=Find(b[i]);
		c[i]=Find(c[i]);
		d[i]=Find(d[i]);
	}
}
void build(ll l=0,ll r=m-1,ll ind=1){
	if(l==r){
		set<pll>s;
		s.clear();
		REP(i,n){
			s.insert(a[i][l]);
			vall[ind].PB(a[i][l]);
			valr[ind].PB(a[i][l]);
		}
		Sz[ind]=sz(s);
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	vpll vrl=vall[2*ind+1],vrr=valr[2*ind+1],vll=vall[2*ind],vlr=valr[2*ind];
	mrgz=0;
	merge(vll,vlr,vrl,vrr);
	vall[ind]=vll;
	valr[ind]=vrr;
	Sz[ind]=Sz[2*ind]+Sz[2*ind+1]-mrgz;
}
void ask(ll targl,ll targr,ll l=0,ll r=m-1,ll ind=1){
	if(l>r)return;
	if(r<targl||targr<l)return;
	if(targl<=l&&r<=targr){
		decompos.PB(ind);
		return;
	}
	ll mid=(l+r)/2;
	ask(targl,targr,l,mid,2*ind);
	ask(targl,targr,mid+1,r,2*ind+1);
}
ll solve(ll l,ll r){
	decompos.clear();
	ask(l-1,r-1);
	vpll vll=vall[decompos[0]],vlr=valr[decompos[0]],vrl,vrr;
	ll ans=Sz[decompos[0]];
	FOR(i,1,sz(decompos)-1){
		mrgz=0;
		vrl=vall[decompos[i]];
		vrr=valr[decompos[i]];
		merge(vll,vlr,vrl,vrr);
		vlr=vrr;
		ans=ans+Sz[decompos[i]]-mrgz;
	}
	return ans;
}
int main(){
	cin>>n>>m>>q;
	REP(i,n){
		REP(j,m)
			scanf("%d",&a[i][j].F);
	}
	ll cmp=0;
	REP(j,m){
		REP(i,n){
			a[i][j].S=cmp++;
			while(i<n-1&&a[i][j].F==a[i+1][j].F){
				a[i+1][j].S=a[i][j].S;
				i++;
			}
		}
	}
	build();
	REP(i,q){
		ll l,r;scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r));
	}
}