// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POF pop_front
#define POB pop_back
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

const ll inf=1e18;
const ll maxn=2e5+10;

ll a[maxn],ans[maxn];
deque<pll>d;
deque<ll>st;
int main(){
	ll n,m;cin>>n>>m;
	REP(i,n)
		cin>>a[i];
	REP(i,m){
		ll x,y;cin>>y>>x;
		x--;
		while(sz(d)&&d.back().F<=x){
			d.pop_back();
		}
		d.PB(MP(x,y));
	}
	FOR(i,0,d[0].F){
		st.PB(a[i]);
	}
	sort(st.begin(),st.end());
	d.PB(MP(-1,-1));
	REP(i,sz(d)-1){
		FORD(j,d[i].F,d[i+1].F+1){
			if(d[i].S==1){
				ans[j]=st[sz(st)-1];
				st.POB();
			}
			else{
				ans[j]=st[0];
				st.POF();
			}
		}
	}
	FOR(q,0,d[0].F)
		cout<<ans[q]<<" ";
	FOR(q,d[0].F+1,n-1)
		cout<<a[q]<<" ";
}