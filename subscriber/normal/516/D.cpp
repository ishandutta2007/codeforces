#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
long long L;
vector<pair<int, int> >v[N];
long long ds[N], de[N];

int p[N], sz[N];

void dfs1(int x, int p) {
	ds[x] = 0;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i].F != p) {
		dfs1(v[x][i].F, x);
		ds[x] = max(ds[x], ds[v[x][i].F] + v[x][i].S);
	}
}

void dfs2(int x, int p, long long dd) {
	de[x] = max(ds[x], dd);

	pair<long long, int> m1 = mp(0,0), m2 = mp(0,0);

	for (int i = 0; i < v[x].size(); i++) if (v[x][i].F != p) {
		pair<long long, int> t = mp(ds[v[x][i].F] + v[x][i].S, i);

		if (t > m1) {
			m2 = m1;
			m1 = t;
		} else m2 = max(m2, t);
	}
	for (int i = 0; i < v[x].size(); i++) if (v[x][i].F != p) {
		long long vv;
		if (m1.S == i) vv = m2.F; else vv = m1.F;
		vv = max(vv, dd);
		dfs2(v[x][i].F, x, vv + v[x][i].S);
	} 
}

int get(int x) {
	if (x == p[x]) return x;
	return p[x] = get(p[x]);
}

void merg(int x, int y) {
	if (p[x] == -1 || p[y] == -1) return;
	x = get(x);
	y = get(y);
	if (de[x] < de[y] || de[x] == de[y] && x > y) swap(x, y);
	sz[y] += sz[x];
	p[x] = y;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		v[x].pb(mp(y, z));
		v[y].pb(mp(x, z));
	}
	dfs1(0, 0);
	dfs2(0, 0, 0);

	cin >> m;

	for (int i = 0; i < m; i++) {
		scanf("%I64d", &L);
		vector<pair<long long, int> > ev;
		for (int i = 0; i < n; i++) {
			ev.pb(mp(de[i], i + 1));
			ev.pb(mp(de[i] - L, -i));
		}
		sort(ev.rbegin(), ev.rend());
		for (int i = 0; i < n; i++) p[i] = -1;
		int ans = 0;
		for (int i = 0; i < ev.size(); i++) {
			
			if (ev[i].S > 0) {
				int x = ev[i].S - 1;
				p[x] = x;
				sz[x] = 1;
				for (int j = 0; j < v[x].size(); j++) merg(x, v[x][j].F);
				ans = max(ans, sz[get(x)]);
			} else {
				int x = -ev[i].S;
				sz[get(x)]--;
				p[x] = -1;
			}
		}
		printf("%d\n", ans);

	}

	return 0;
}