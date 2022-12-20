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
const ll mod=1e9+7;

vector<pll>v[maxn];
ll val[maxn];
bool finall[maxn];

priority_queue<pll,vector<pll>,greater<pll> > pq;

int main(){
	ll n,m;cin>>n>>m;
	REP(i,m){
		ll a,b,c;cin>>a>>b>>c;
		a--;b--;c*=2;
		v[a].PB(MP(b,c));
		v[b].PB(MP(a,c));
	}
	REP(i,n){
		cin>>val[i];
		pq.push(MP(val[i],i));
	}
	while(sz(pq)){
		pll p=pq.top();
		pq.pop();
		if(finall[p.S])
			continue;
		finall[p.S]=1;
		REP(i,sz(v[p.S])){
			ll y=v[p.S][i].F;
			ll w=v[p.S][i].S;
			if(val[y]>val[p.S]+w){
				val[y]=val[p.S]+w;
				pq.push(MP(val[y],y));
			}
		}
	}
	REP(i,n)
		cout<<val[i]<<" ";
}