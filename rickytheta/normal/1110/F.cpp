#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,q;
int par[525252], parw[525252];
pair<pii,pii> query[525252];
ll ans[525252];

int indeg[525252];
int lch[525252], rch[525252];
ll dist[525252];

const int N = 1<<19;
pll dat[2*N];
ll add(int l, int r, ll v, int a, int b, int k){
	if(r<=a || b<=l)return dat[k].first;
	if(l<=a && b<=r){
		dat[k].second += v;
		dat[k].first += v;
		return dat[k].first;
	}else{
		int m = (a+b)/2;
		dat[k].first = dat[k].second + min(add(l,r,v,a,m,2*k+1), add(l,r,v,m,b,2*k+2));
		return dat[k].first;
	}
}
ll qmin(int l, int r, int a, int b, int k){
	if(r<=a || b<=l)return 1ll<<60;
	if(l<=a && b<=r)return dat[k].first;
	int m = (a+b)/2;
	return dat[k].second + min(qmin(l,r,a,m,2*k+1),qmin(l,r,m,b,2*k+2));
}

int main(){
	scanf("%d%d",&n,&q);
	par[0] = -1;
	FOR(i,1,n){
		scanf("%d%d",par+i,parw+i);
		par[i]--;
		indeg[par[i]]++;
	}
	REP(i,q){
		int l,r,v;
		scanf("%d%d%d",&v,&l,&r);
		query[i] = make_pair(pii(v-1,i),pii(l-1,r));
	}
	sort(query,query+q);
	// tree
	REP(i,n){
		if(par[i]!=-1)dist[i] = dist[par[i]] + parw[i];
		dat[i+N-1].first = indeg[i]==0 ? dist[i] : 1ll<<60;
	}
	fill(lch,lch+n,n+1);
	fill(rch,rch+n,-1);
	FORR(i,0,n){
		if(indeg[i]==0)lch[i] = rch[i] = i;
		if(par[i]!=-1){
			CHMIN(lch[par[i]], lch[i]);
			CHMAX(rch[par[i]], rch[i]);
		}
	}
	// seg
	FORR(i,0,N-1){
		dat[i].first = min(dat[2*i+1].first, dat[2*i+2].first);
	}
	// query for 0
	int qit = 0;
	while(qit<q && query[qit].first.first == 0){
		pair<pii,pii> PP = query[qit++];
		int l = PP.second.first;
		int r = PP.second.second;
		int id = PP.first.second;
		ans[id] = qmin(l,r,0,N,0);
	}
	stack<int> trail; trail.push(0);
	ll alladd = 0;
	// dp
	FOR(i,1,n){
		// trail pop
		while(trail.top() != par[i]){
			int p = trail.top(); trail.pop();
			int w = parw[p];
			alladd -= w;
			add(lch[p], rch[p]+1, 2ll*w, 0, N, 0);
		}
		// trail push
		trail.push(i);
		int w = parw[i];
		alladd += w;
		add(lch[i], rch[i]+1, -2ll*w, 0, N, 0);
		// calc ans
		while(qit<q && query[qit].first.first == i){
			pair<pii,pii> PP = query[qit++];
			int l = PP.second.first;
			int r = PP.second.second;
			int id = PP.first.second;
			ans[id] = qmin(l,r,0,N,0) + alladd;
		}
	}
	REP(i,q)printf("%lld\n",ans[i]);
	return 0;
}