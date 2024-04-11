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
const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll MAX=15e5;

#pragma GCC Optimize("Ofast")

vector<pll>qu[maxn];
ll a[maxn],ans[maxn];
bool is[MAX];
vector<ll>v;
ll cnt;
ll tw[maxn];

int main(){
	tw[0]=1;
	FOR(i,1,maxn-1){
		tw[i]=(tw[i-1]*2)%mod;
	}
	v.PB(0);
	is[0]=1;
	ll n,q;cin>>n>>q;
	REP(i,n){
		cin>>a[i];
	}
	REP(i,q){
		ll l,x;cin>>l>>x;
		qu[--l].PB(MP(x,i));
	}
	REP(i,n){
		if(is[a[i]]){
			cnt++;
		}
		else{
			ll SZ=sz(v);
			REP(j,SZ){
				ll num=v[j]^a[i];
				v.PB(num);
				is[num]=1;
			}
		}
		REP(j,sz(qu[i])){
			ans[qu[i][j].S]=(is[qu[i][j].F]?tw[cnt]:0);
		}
	}
	REP(i,q)
		cout<<ans[i]<<endl;
}