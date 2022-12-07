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
#define N 211111

#define TASK "1"

using namespace std;

int p[20][N], mi[20][N];
vector<pair<int, int> > v[N];
pair<pair<int, int>, pair<int, int> > q[N];
int d[N];

int we[N];

multiset<int> S[N];
int ans[N];
int pp[N];

int n, m;

vector<pair<int, int > > za[N];
int in[N];



int get(int x) {
	if (pp[x] == x) return x;
	return pp[x] = get(pp[x]);
}

void dfs(int x, int pr, int dd) {
	d[x] = dd;
	p[0][x] = pr;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i].F;
		if (to == pr) continue;
		dfs(to, x, dd + 1);
		mi[0][to] = we[v[x][i].S];
	}
}

int lca(int x, int y) {
	for (int i = 19; i >= 0; i--) if (d[p[i][x]] >= d[y]) x = p[i][x];
	for (int i = 19; i >= 0; i--) if (d[p[i][y]] >= d[x]) y = p[i][y];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) if (p[i][y] != p[i][x] ) {
		y = p[i][y];
		x = p[i][x];
	}
	return p[0][x];
}

void go(int x, int id) {
	vector<int> e;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i].F;
		if (p[0][to] == x) {
			go(to, v[x][i].S);
			e.pb(to);
		}
	}
	if (id == -1) return;

	if (e.size() > 0) {
		int la = -1;
		for (int i = 0; i < e.size(); i++) if (la == -1 || S[e[i]].size() > S[e[la]].size()) la = i;
		swap(S[x], S[e[la]]);
		for (int i = 0; i < e.size(); i++) if (i != la) S[x].insert(S[e[i]].begin(), S[e[i]].end());
	}

	for (int i = 0; i < za[x].size(); i++) {
		if (za[x][i].S == 1) {
			S[x].insert(za[x][i].F);
		} else {
			S[x].erase(S[x].find(za[x][i].F));
		}
	}



	if (S[x].size() > 0) {
		ans[id] = *S[x].begin();
		ans[id]--;
	} else ans[id] = -1;

}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin  >> q[i].S.F >> q[i].S.S >> q[i].F.F;
		q[i].F.S = i;
		q[i].S.F--;
		q[i].S.S--;
		we[i] = q[i].F.F;
	}
	sort(q, q + m);

	for (int i = 0; i < n; i++) pp[i] = i;
	for (int i = 0; i < m; i++) {
		int x = q[i].S.F;
		int y = q[i].S.S;
		in[i] = 1;
		if (get(x) == get(y)) {
			in[i] = 0;
			continue;
		}
		v[x].pb(mp(y, q[i].F.S));
		v[y].pb(mp(x, q[i].F.S));

		pp[get(x)] = get(y);
	}
	dfs(0, 0, 0);
	for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) p[i][j] = p[i - 1][p[i - 1][j]];
	for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) mi[i][j] = max(mi[i - 1][j], mi[i - 1][p[i - 1][j]]);

	for (int i = 0; i < m; i++) if (!in[i]) {
		int x = q[i].S.F;
		int y = q[i].S.S;
		int z = lca(x, y);
		za[x].pb(mp(q[i].F.F, 1));
		za[y].pb(mp(q[i].F.F, 1));
		za[z].pb(mp(q[i].F.F, -1));
		za[z].pb(mp(q[i].F.F, -1));


		ans[q[i].F.S] = 0;
		for (int j = 19; j >= 0; j--) if (d[p[j][x]] > d[z]) {
			ans[q[i].F.S] = max(ans[q[i].F.S], mi[j][x]);
			x = p[j][x];
		}
		if (x != z) ans[q[i].F.S] = max(ans[q[i].F.S], mi[0][x]);

		x = y;
		for (int j = 19; j >= 0; j--) if (d[p[j][x]] > d[z]) {
			ans[q[i].F.S] = max(ans[q[i].F.S], mi[j][x]);
			x = p[j][x];
		}
		if (x != z) ans[q[i].F.S] = max(ans[q[i].F.S], mi[0][x]);
		ans[q[i].F.S]--;
	}
	go(0, -1);
	for (int i = 0; i < m; i++) cout << ans[i] << " ";
	return 0;
}