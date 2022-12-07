#include<bits/stdc++.h>
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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 811111

#define TASK "1"

using namespace std;

vector<int> v[N];
int n;
int sz[N], ma[N];
int ans[N];

void dfs(int x, int p) {
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		dfs(to, x);
		sz[x] += sz[to];
	}
}

void rec(int x, int p) {
	ma[x] = -1;
	if (sz[x] * 2 <= n) ma[x] = max(ma[x], sz[x]);
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		rec(to, x);
		ma[x] = max(ma[x], ma[to]);
	}
}

void calc(int x, int p, int o) {
	ans[x] = 0;
	int bad = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		if (sz[to] * 2 >= n) {
			if ((sz[to] - ma[to]) * 2 <= n) ans[x] = 1;
			bad = 1;
		}
	}
	if ((n - sz[x]) * 2 >= n) {
		if ((n - sz[x] - o) * 2 <= n) ans[x] = 1;
		bad = 1;
	}
	if (!bad) ans[x] = 1;
	vector<pair<int, int > > e;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		e.pb(mp(ma[to], to));
	}
	sort(e.rbegin(), e.rend());
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		int oo = o;
		if ((n - sz[to]) * 2 <= n) oo = max(oo, (n - sz[to]));
		if (e[0].S != to) {
			oo = max(oo, e[0].F);
		} else if (e.size() > 1) {
			oo = max(oo, e[1].F);
		}
		calc(to, x, oo);
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0, 0);
	rec(0, 0);

	calc(0, 0, -1);
	for (int i = 0; i < n; i++) cout << ans[i] << " ";	

	return 0;
}