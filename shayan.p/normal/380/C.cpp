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

const ll maxn=1e6+10;

string str;
ll pref[4*maxn],suf[4*maxn],buf[4*maxn];

void build(ll l=0,ll r=sz(str)-1,ll ind=1){
	if(l==r){
		if(str[l]=='(')
			suf[ind]=1;
		else
			pref[ind]=1;
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	ll M=min(suf[2*ind],pref[2*ind+1]);
	buf[ind]=buf[2*ind]+buf[2*ind+1]+2*M;
	suf[ind]=suf[2*ind+1]+suf[2*ind]-M;
	pref[ind]=pref[2*ind]+pref[2*ind+1]-M;
}

pair<pll,ll> ask(ll f,ll s,ll l=0,ll r=sz(str)-1,ll ind=1){
	if(l>r)return MP(MP(0,0),0);
	if(s<l||r<f) return MP(MP(0,0),0);
	if(f<=l&&r<=s){
//		cout<<":::::: "<<l<<" "<<r<<"	"<<pref[ind]<<" "<<suf[ind]<<" "<<buf[ind]<<endl;
		return MP(MP(pref[ind],suf[ind]),buf[ind]);
	}
	pair<pll,ll>a,b,c;
	ll mid=(l+r)/2;
	a=ask(f,s,l,mid,2*ind);
	b=ask(f,s,mid+1,r,2*ind+1);
	ll M=min(a.F.S,b.F.F);
	c.S=a.S+b.S+2*M;
	c.F.S=a.F.S+b.F.S-M;
	c.F.F=a.F.F+b.F.F-M;
	return c;
}

int main(){
	cin>>str;
	build();
	ll m;cin>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		a--;b--;
		pair<pll,ll> p=ask(a,b);
		cout<<p.S<<endl;
	}
}