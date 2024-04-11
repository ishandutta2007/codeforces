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

#pragma GCC Optimize("Ofast")

vector<ll>poso,posz;

void FILL(ll num,vector<ll>&v){
	if(num==0){
		v.PB(0);
		v.PB(1);
		return;
	}
	ll sq=sqrt(1+(8*num));
	if(sq*sq!=(1+(8*num)))
		return;
	v.PB((1+sq)/2);
}

void make(ll o,ll z,ll zo,ll oz){
	if(zo+oz!=(o*z))
		return;
	if(o==0&&z==0)
		return;
	if(o==0||z==0){
		REP(i,o)
			cout<<1;
		REP(i,z)
			cout<<0;
		exit(0);
	}
	REP(i,(oz/z))
		cout<<1;
	ll r=oz%z;
	ll l=z-r;
	REP(i,l)
		cout<<0;
	if(r!=0)
		cout<<1;
	REP(i,r)
		cout<<0;
	REP(i,o-((oz/z)+(oz%z!=0)))	
		cout<<1;
	exit(0);
}

int main(){
	ll zz,zo,oz,oo;cin>>zz>>zo>>oz>>oo;
	FILL(zz,posz);
	FILL(oo,poso);
	REP(i,sz(poso))
		REP(j,sz(posz))
			make(poso[i],posz[j],zo,oz);
	cout<<"Impossible";
}