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
typedef pair<ll,pll> pl3;

const ll inf=1e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

set<pl3>st;
set<pll>vis;
ll n,m,r,k;
ll dx[4],dy[4];

ll calc(ll x,ll y){
	return (min(x+r-1,n-1)-max(x,r-1)+1)*(min(y+r-1,m-1)-max(y,r-1)+1);
}
int main(){
	dx[0]=1;dx[1]=0;dx[2]=-1;dx[3]=0;
	dy[0]=0;dy[1]=1;dy[2]=0;dy[3]=-1;
	cin>>n>>m>>r>>k;
	st.insert(MP(calc(n/2,m/2),MP(n/2,m/2)));
	vis.insert(MP(n/2,m/2));
	ll ans=0;
	REP(i,k){
		pl3 p=*st.rbegin();
		st.erase(p);
		ans+=p.F;
		REP(i,4){
			ll x=p.S.F+dx[i],y=p.S.S+dy[i];
			if(0<=x&&x<n&&0<=y&&y<m&&!vis.count(MP(x,y))){
				vis.insert(MP(x,y));
				st.insert(MP(calc(x,y),MP(x,y)));
			}
		}
	}
	cout<<setprecision(9)<<fixed<<(ld(ans)/ld((m-r+1)*(n-r+1)));
}