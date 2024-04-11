// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=1e5+10;

struct Hull{// Min Hull // increasing
    vector<pll>v;
    ll get(pll a,ll x){
	return a.F*x+a.S;
    }
    bool is_bad(pll ps,pll nw,pll fu){
	if(nw.F == fu.F) return fu.S<=nw.S;
	return (nw.S-fu.S)*(nw.F-ps.F) >= (nw.S-ps.S)*(nw.F-fu.F);
    }
    void add(pll p){
	v.PB(p);
	while(sz(v)>2 && is_bad(v[sz(v)-3],v[sz(v)-2],v[sz(v)-1]) ){
	    v[sz(v)-2]=v[sz(v)-1];
	    v.POB();
	}
    }
    ll ask(ll x){
	ll l=0,r=sz(v)-1;
	while(l<r){
	    ll mid=(l+r)/2;
	    if(get(v[mid],x) < get(v[mid+1],x))
		r=mid;
	    else
		l=mid+1;
	}
	return get(v[l],x);
    }
};

ll n,sm[maxn];
pll a[maxn];
Hull hull[4*maxn];

void Merge(Hull &a,Hull b,Hull c){
    ll pb=0,pc=0;
    while((sz(b.v)+sz(c.v))>(pb+pc)){
	if(pb==sz(b.v))
	    a.add(c.v[pc++]);
	else if(pc==sz(c.v))
	    a.add(b.v[pb++]);
	else if(b.v[pb].F<c.v[pc].F)
	    a.add(b.v[pb++]);
	else
	    a.add(c.v[pc++]);
    }
}

void build(ll l=1,ll r=n,ll id=1){
    if(l==r){
	hull[id].add(a[l]);
	return;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    Merge(hull[id],hull[2*id],hull[2*id+1]);
}

ll ask(ll f,ll s,ll x,ll l=1,ll r=n,ll id=1){
    if(l>r || s<l || r<f)return inf;
    if(f<=l&&r<=s)return hull[id].ask(x);
    ll mid=(l+r)/2;
    return min(ask(f,s,x,l,mid,2*id),ask(f,s,x,mid+1,r,2*id+1));
}

int main(){
    cin>>n;
    FOR(i,1,n){
	cin>>a[i].F;
	sm[i]=sm[i-1]+a[i].F;
    }
    FOR(i,1,n){
	a[i].S=sm[n]-sm[i]+a[i].F*i;
	a[i].F*=-1;
    }
    build();
    ll q;cin>>q;
    while(q--){
	ll x,y;cin>>x>>y;
	x=y-x+1;
	cout<<ask(x,y,x-1)-sm[n]+sm[y]<<endl;
    }
}