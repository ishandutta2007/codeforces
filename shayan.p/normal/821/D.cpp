// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

struct group{
	set<pll>s;
	ll u,d,r,l;
	void Clear(){
		s.clear();
		u=inf;
		d=0;
		r=0;
		l=inf;
	}
};

group make_group(pll p,ll U,ll D,ll R,ll L){
	group g;
	g.s.insert(p);
	g.u=U;
	g.d=D;
	g.r=R;
	g.l=L;
	return g;
}

set<pll>st;
vector<group> v;
ll n,m;

void dfs(pll p,group &g){
	st.erase(p);
	g.s.insert(p);
	g.u=min(g.u,p.F);
	g.d=max(g.d,p.F);
	g.r=max(g.r,p.S);
	g.l=min(g.l,p.S);
	ll a=p.F;
	ll b=p.S;
	FOR(i,-1,1){
		FOR(j,-1,1){
			if(i==0 xor j==0){
				ll A=a+i,B=b+j;
				if(0<A&&A<=n&&0<B&&B<=m){
					if(st.count(MP(A,B))){
						dfs(MP(A,B),g);
					}
				}
			}
		}
	}
}

int main(){
	ll k;cin>>n>>m>>k;
	ll start;
	REP(i,k){
		ll a,b;cin>>a>>b;
		st.insert(MP(a,b));
	}
	if(!st.count(MP(n,m))){
		v.PB(make_group(MP(n+1,m+1),n+1,n+1,m+1,m+1));
	}
	while(sz(st)){
		group g;
		g.Clear();
		dfs(*st.begin(),g);
		v.PB(g);
		if(g.s.count(MP(1,1))){
			start=sz(v)-1;
		}
	}
//	REP(i,sz(v)){
//		cout<<v[i].u<<" "<<v[i].d<<" "<<v[i].l<<" "<<v[i].r<<endl;
//	}
	vector<ll>adj[sz(v)+10];///Memory limit
	
	
	FOR(i,0,sz(v)-1){
		FOR(j,i+1,sz(v)-1){
			if(!((v[i].u>v[j].d+2||v[i].d+2<v[j].u)&&(v[i].r+2<v[j].l||v[i].l>v[j].r+2))){
				adj[i].PB(j);
				adj[j].PB(i);
			}
		}
	}
	set<ll>vis;
	queue<pll>q;
	q.push(MP(start,0));//node depth
	vis.insert(start);
	while(sz(q)){
		pll p=q.front();
//		cout<<p.F<<" "<<p.S<<endl;
		q.pop();
		if(v[p.F].s.count(MP(n,m))||v[p.F].s.count(MP(n+1,m+1))){//bug?
			cout<<p.S;
			return 0;
		}
		REP(i,sz(adj[p.F])){
			ll y=adj[p.F][i];
			if(!vis.count(y)){
				vis.insert(y);
				q.push(MP(y,p.S+1));
			}
		}
	}
	cout<<-1;
}