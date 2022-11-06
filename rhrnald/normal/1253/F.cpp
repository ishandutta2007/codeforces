#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m,k,q,x,y,d;
vector<pii> v[N];

typedef pair<ll,int> pli;
typedef pair<pli,int> ppi;
priority_queue<ppi, vector<ppi>, greater<ppi>> Q;
pli dis[N];
bool vst[N];
int p[N];
int h(int cur) {
	if(p[cur]==cur) return cur;
	p[cur]=h(p[cur]);
	return p[cur];
}
typedef pair<pii, int> ppp;
vector<ppp> E;

typedef pair<ll, pii> ppl;
vector<ppl> u;



vector<pli> G[N];
vector<pli> T[N];
void add_edge(int x, int y, ll d) {
	G[x].push_back({d,y});
	G[y].push_back({d,x});
}
int hh[N];
ll dd[N];
void dfs(int cur, int par) {
	for(pli e : G[cur]) {
		int nxt=e.second;
		if(nxt==par) continue;
		p[nxt]=cur;
		hh[nxt]=hh[cur]+1;
		dd[nxt]=e.first;
		dfs(nxt, cur);
	}
}
int p1[N][20];
ll p2[N][20];
void make() {
	for(int i=1; i<=k; i++) p1[i][0]=p[i], p2[i][0]=dd[i];//, printf("%d %lld\n",p[i],dd[i]);
	for(int t=1; t<20; t++) {
		for(int i=1; i<=k; i++) {
			int nxt=p1[i][t-1];
			p1[i][t]=p1[nxt][t-1];
			p2[i][t]=max(p2[i][t-1], p2[nxt][t-1]);
		}
	}
}
void makeTree() {
	p[1]=0;
	dfs(1,0);
	make();
}
void solve(int x, int y) {
	if(hh[x]<hh[y]) swap(x,y);
	ll M=0;
	int d=hh[x]-hh[y];
	int B=1, i=0;
	while(B+B<=d) B=B+B, i++;
	while(hh[x]>hh[y]) {
		while(hh[x]-hh[y]<B) B/=2, i--;
		M=max(M, p2[x][i]);
		x=p1[x][i];
	}

	i=19;
	while(x!=y) {
		if(p[x]==p[y]) {
			M=max({M,dd[x],dd[y]});
			break;
		}
		while(p1[x][i]==p1[y][i]) i--;
		M=max({M, p2[x][i], p2[y][i]});
		x=p1[x][i];
		y=p1[y][i];
	}
	printf("%lld\n", M);
}
int main(void){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &d);
		v[x].push_back({y,d});
		v[y].push_back({x,d});
		E.push_back({{x,y},d});
	}
	for(int i=1; i<=n; i++) p[i]=i;

	for(int i=1; i<=k; i++) Q.push({{0,i},i}), dis[i]={0,i};
	for(int i=k+1; i<=n; i++) dis[i]={LINF,-1};

	while(!Q.empty()) {
		ppi temp=Q.top(); Q.pop();
		int cur=temp.second;
		ll d=temp.first.first;
		int idx=temp.first.second;
		if(vst[cur]) continue;
		vst[cur]=true;

		for(int i=0; i<sz(v[cur]); i++) {
			pli nw={d+v[cur][i].second,idx};
			int nxt=v[cur][i].first;
			if(dis[nxt]>nw) {
				dis[nxt]=nw;
				Q.push({nw, nxt});
			}
		}
	}

	for(ppp e: E) {
		x=e.first.first;
		y=e.first.second;
		d=e.second;
		u.push_back({dis[x].first+dis[y].first+d, {dis[x].second, dis[y].second}});
	}
	sort(all(u));
	
	for(ppl e : u) {
		int x=h(e.second.first);
		int y=h(e.second.second);
		if(x!=y) {
			p[x]=y;
			add_edge(x,y,e.first);
//			printf("%d %d %lld\n", x, y, e.first);
		}
	}
	makeTree();
	for(int i=0; i<q; i++) {
		scanf("%d%d", &x, &y);
		solve(x,y);
	}
}