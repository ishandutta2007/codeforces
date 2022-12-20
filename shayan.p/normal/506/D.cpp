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

#pragma GCC Optimize("Ofast")

struct Dsu{
	ll c[maxn];
	stack<ll>st[maxn],used_st,used_c;
	Dsu(){
		REP(i,maxn){
			c[i]=i;
			st[i].push(i);
		}
	}
	bool same(ll x,ll y){
		return c[x]==c[y];
	}
	void Merge(ll x,ll y){
		if(c[x]==c[y])return;
		x=c[x];y=c[y];
		if(sz(st[x])<sz(st[y])){
			while(sz(st[x])){
				ll tp=st[x].top();
				st[x].pop();
				st[y].push(tp);
				c[tp]=y;
				used_st.push(y);
				used_st.push(x);
				used_c.push(tp);
			}
		}
		else{
			while(sz(st[y])){
				ll tp=st[y].top();
				st[y].pop();
				st[x].push(tp);
				c[tp]=x;
				used_st.push(x);
				used_st.push(y);
				used_c.push(tp);
			}
		}
	}
	void Clear(){
		while(sz(used_st)){
			ll tp=used_st.top();
			used_st.pop();
			if(!st[tp].empty())
				st[tp].pop();
			if(st[tp].empty())
				st[tp].push(tp);
		}
		while(sz(used_c)){
			ll tp=used_c.top();
			used_c.pop();
			c[tp]=tp;
		}
	}
};Dsu dsu;
stack<pll>color[maxn];
pll qu[maxn];
map<pll,vector<ll> >mp;
ll ans[maxn];
set<ll>used;
ll q,n,m;

void attack1(){
	REP(i,q){
		ans[i]+=dsu.same(qu[i].F,qu[i].S);
	}
}
void attack2(){
	vector<ll>v;v.clear();
	for(set<ll>::iterator it=used.begin();it!=used.end();it++)
		v.PB(*it);
	REP(i,sz(v)){
		REP(j,sz(v)){
			if(mp.count(MP(v[i],v[j]))){
				vector<ll>&vec=mp[MP(v[i],v[j])];
				if(dsu.same(v[i],v[j]))
					REP(k,sz(vec))
						ans[vec[k]]++;
			}
		}
	}
}
void component_dsu(ll num){
	dsu.Clear();
	used.clear();
	while(!color[num].empty()){
		pll p=color[num].top();
		color[num].pop();
		used.insert(p.F);
		used.insert(p.S);
		dsu.Merge(p.F,p.S);
	}
}

int main(){
	cin>>n>>m;
	REP(i,m){
		ll a,b,c;cin>>a>>b>>c;
		color[c].push(MP(a,b));
	}
	cin>>q;
	REP(i,q){
		cin>>qu[i].F>>qu[i].S;
		mp[qu[i]].PB(i);
	}
	ll sq=sqrt(m);
	FOR(i,1,maxn-1){
		ll num=sz(color[i]);
		if(sz(color[i])==0)
			continue;
		component_dsu(i);
		if(sz(used)==0)
			continue;
		if(num>sq)
			attack1();
		else
			attack2();
	}
	REP(i,q)
		cout<<ans[i]<<endl;
}