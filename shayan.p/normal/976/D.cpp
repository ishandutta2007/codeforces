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
const ll maxn=310;
const ll mod=1e9+7;
const ll MAX=1010;

#pragma GCC Optimize("Ofast")

bool is[MAX][MAX];
vector<pll>ans;
ll d[maxn];
ll t=1;

void add(ll a,ll b){
	is[a][b]=is[b][a]=1;
}

void build(ll l,ll r,ll neg){
	if(l==r){
		ll s=d[l]-neg;
		REP(i,(s+1)){
			REP(j,(s+1)){
				add(t+i,t+j);
			}
		}
		t+=s+1;
		return;
	}
	if(l+1==r){
		ll s1=d[l]-neg;
		ll s2=d[r]-neg;
		REP(i,s1){
			REP(j,(s2+1)){
				add(t+i,t+j);
			}
		}
		t+=s2+1;
		return;
	}
	ll T0=t;
	build(l+1,r-1,d[l]);
	ll s1=d[l]-neg;
	ll s2=d[r]-neg;
	REP(i,s1){
		REP(j,(s2+1)){
			add(i+t,(T0+j));
		}
	}
	t+=d[r]-d[r-1]+d[l]-neg;
}

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>d[i];
	build(0,n-1,0);
	REP(i,MAX){
		REP(j,MAX){
			if(i<=j)
				continue;
			if(is[i][j])
				ans.PB(MP(i,j));
		}
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<ans[i].F<<" "<<ans[i].S<<endl;		
}