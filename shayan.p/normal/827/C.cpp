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
const ll mod=1e9+7;
const ll maxn=1e5+10;

#pragma GCC Optimize("Ofast")

inline ll change(char ch){
	if(ch=='A')
		return 0;
	if(ch=='T')
		return 1;
	if(ch=='G')
		return 2;
	if(ch=='C')
		return 3;
}
struct fenwick{
	ll val[maxn];
	void add(ll ind,ll num){
		while(ind<maxn){
			val[ind]+=num;
			ind+=(ind & -ind);
		}
	}
	ll ask(ll ind){
		if(ind==0)return 0;
		ll sm=0;
		while(ind>0){
			sm+=val[ind];
			ind-=(ind & -ind);
		}
		return sm;
	}
};
fenwick fen[11][11][5];

ll a[maxn];
// a t g c
int main(){
	string s;cin>>s;
	ll n=sz(s);
	FOR(i,1,n)
		a[i]=change(s[i-1]);
	FOR(i,1,n)
		FOR(md,1,10)
			fen[md][i%md][a[i]].add(i,1);
	ll q;cin>>q;
	while(q--){
		ll task;cin>>task;
		if(task==1){
			ll ind,x;char c;cin>>ind>>c;
			x=change(c);
			FOR(md,1,10){
				fen[md][ind%md][a[ind]].add(ind,-1);
				fen[md][ind%md][x].add(ind,1);
			}
			a[ind]=x;
		}
		else{
			ll l,r;string e;cin>>l>>r>>e;
			ll md=sz(e),ans=0;
			REP(i,sz(e))
				ans+=fen[md][(l+i)%md][change(e[i])].ask(r)-fen[md][(l+i)%md][change(e[i])].ask(l-1);
			cout<<ans<<endl;
		}
	}
}