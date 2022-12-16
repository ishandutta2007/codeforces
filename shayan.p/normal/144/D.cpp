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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;
const ll inf=4e18;

vector<pll>v[maxn];
priority_queue<pll,vector<pll>,greater<pll> >pq;
ll shp[maxn];
stack<pair<pll,ll> >edge;

int main(){
	ll n,m,s;cin>>n>>m>>s;
	s--;
	REP(i,m){
		ll a,b,w;cin>>a>>b>>w;
		a--;b--;
		v[a].PB(MP(b,w));
		v[b].PB(MP(a,w));
		edge.push(MP(MP(a,b),w));
	}
	fill(shp,shp+maxn,inf);
	pq.push(MP(ll(0),s));
	shp[s]=0;
	while(sz(pq)){
		ll tp=pq.top().S;
		pq.pop();
		REP(i,sz(v[tp])){
			ll y=v[tp][i].F,w=v[tp][i].S;
			if(shp[tp]+w<shp[y]){
				shp[y]=shp[tp]+w;
				pq.push(MP(shp[y],y));
			}
		}
	}
	
	ll L,ans=0;cin>>L;
	REP(i,n)
		if(shp[i]==L)
			ans++;
	while(sz(edge)){
		ll a=edge.top().F.F,b=edge.top().F.S,w=edge.top().S;
		edge.pop();
		ll len1=L-shp[a],len2=L-shp[b];
		if(len1>0&&L<=(w-len1+shp[b])&&len1<w)
			ans++;
		if(len2>0&&L<(w-len2+shp[a])&&len2<w)//strict
			ans++;
	}
	cout<<ans;
}