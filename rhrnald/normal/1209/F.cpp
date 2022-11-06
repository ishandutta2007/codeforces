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
const int MOD=1000000007;

const int N = 1000001;
int n,m;
int len[N];
int x[N],y[N];
void make() {
	for(int i=1; i<10; i++) len[i]=1;
	for(int i=10; i<100; i++) len[i]=2;
	for(int i=100; i<1000; i++) len[i]=3;
	for(int i=1000; i<10000; i++) len[i]=4;
	for(int i=10000; i<100000; i++) len[i]=5;
	len[100000]=6;
}
vector<pii> F[N], G[N];

priority_queue<pii, vector<pii>, greater<pii>> Q;
int dis[N];

int cur;

void connect(int from, int to, int d) {
	vector<int> t1, t2;
	while(d) t2.push_back(d%10), d/=10; reverse(all(t2));
	t1.push_back(from);
	for(int i=0; i<sz(t2)-1; i++) t1.push_back(cur++);
	t1.push_back(to);
	for(int i=0; i<sz(t2); i++) G[t1[i]].push_back({t1[i+1], t2[i]});
	for(int i=1; i<sz(t1)-1; i++) dis[t1[i]]=dis[from]+i;
}
void Dij() {
	for(int i=1; i<=n; i++) dis[i]=INF;
	dis[1]=0;
	Q.push({0,1});
	while(!Q.empty()) {
		int cur=Q.top().second;
		Q.pop();

		for(pii nxt:F[cur]) {
			if(dis[nxt.first]>dis[cur]+len[nxt.second]) {
				dis[nxt.first]=dis[cur]+len[nxt.second];
				Q.push({dis[nxt.first], nxt.first});
			}
		}
	}
	cur=n+1;
	for(int i=1; i<=m; i++) {
		if(dis[x[i]]+len[i]==dis[y[i]]) connect(x[i], y[i], i);
		if(dis[y[i]]+len[i]==dis[x[i]]) connect(y[i], x[i], i);
	}
}

int ord[N];
pii prv[N];
ll val[N];
bool cmp(int x, int y) {
	if(ord[prv[x].first]==ord[prv[y].first]) return prv[x].second<prv[y].second;
	return ord[prv[x].first]<ord[prv[y].first];
}
bool cmp2(int x, int y) {
	return ord[prv[x].first]==ord[prv[y].first] && prv[x].second==prv[y].second;
}
vector<int> v[N];
void solve() {
	prv[1]={0,0}; val[1]=0;
	for(int i=1; i<=cur; i++) v[dis[i]].push_back(i);

	for(int i=0; !v[i].empty(); i++) {
		sort(all(v[i]), cmp);

		ord[v[i][0]]=0;
		for(int j=1; j<sz(v[i]); j++) {
			if(cmp2(v[i][j-1], v[i][j])) ord[v[i][j]]=ord[v[i][j-1]];
			else ord[v[i][j]]=ord[v[i][j-1]]+1;
		}
		for(int e : v[i]) val[e]=(val[prv[e].first]*10+prv[e].second)%MOD;
		for(int cur : v[i]) {
			for(pii e : G[cur]) {
				int nxt=e.first;
				int id=e.second;
				if(!prv[nxt].first || make_pair(ord[prv[nxt].first], prv[nxt].second)>make_pair(ord[cur], id)) prv[nxt]={cur, id};
			}
		}
	}
}
int main(void){
	make();
	scanf("%d%d", &n, &m);
	int cur=n+1;
	for(int i=1; i<=m; i++) {
		scanf("%d%d", x+i, y+i);
		F[x[i]].push_back({y[i],i});
		F[y[i]].push_back({x[i],i});	
	}
	Dij();
	solve();
	for(int i=2; i<=n; i++) printf("%lld\n", val[i]);
}