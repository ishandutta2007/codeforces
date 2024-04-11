#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define sz(a) ((int)(a.size()))

#define fs first
#define sc second

typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t uint;

typedef ve< int > vi;
typedef pa< int, int > pii;
typedef ve< pii > vpii;

const int INF = 2016000000;

int n, m;
int s, t;
int ans;
vi e_ans;

vi w;
vi mark;
ve< pii > e;
ve< vi > g;

int getV(int e_id, int from) {
	int x, y;
	tie(x, y) = e[e_id];
	return x + y - from;
}

vi used;
vi tin, tout, tup;
vi par;
int timer;

void dfs(int x, int p_id) {
	used[x] = 1;
	tin[x] = ++timer;
	tup[x] = tin[x];
	par[x] = p_id;
	for (int e_id : g[x]) {
		int to = getV(e_id, x);
		if (e_id == p_id || mark[e_id]) {
			continue;
		}
		if (!used[to]) {
			dfs(to, e_id);
			tup[x] = min(tup[x], tup[to]);
		} else {
			tup[x] = min(tup[x], tin[to]);
		}
	}
	tout[x] = ++timer;
}

pii calc(int e_id, int we) {
	pii ans = mp(INF, -1);
	timer = 0;
	mark[e_id] = 1;
	used.assign(n, 0);
	dfs(s, -1);
	mark[e_id] = 0;
	if (!used[t]) {
		return mp(we, -1);
	}
	int cur_v = t;
	while (cur_v != s) {
		int cur_e = par[cur_v];
		int next_v = getV(cur_e, cur_v);
		if (tup[cur_v] > tin[next_v] && we + w[cur_e] < ans.fs) {
			ans = mp(we + w[cur_e], cur_e);
		}
		cur_v = next_v;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ans = INF;
	e_ans.clear();

	cin >> n >> m;
	cin >> s >> t;
	--s, --t;
	e.resize(m);
	w.resize(m);
	g.assign(n, vi());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v >> w[i];
		--u, --v;
		g[u].pb(i);
		g[v].pb(i);
		e[i] = mp(u, v);
	}

	mark.assign(m, 0);
	used.assign(n, 0);
	tin.assign(n, -1);
	par = tout = tup = tin;
	dfs(s, -1);

	if (!used[t]) {
		ans = 0;
	} else {
		int cur_v = t;
		while (cur_v != s) {
			int cur_e = par[cur_v];
			int next_v = getV(cur_e, cur_v);
			pii val = calc(cur_e, w[cur_e]);
			if (val.fs < ans) {
				ans = val.fs;
				e_ans.clear();
				e_ans.pb(cur_e);
				if (val.sc >= 0) {
					e_ans.pb(val.sc);
				}
			}
			cur_v = next_v;
		}
	}

	// output
	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
		cout << sz(e_ans) << '\n';
		for (int x : e_ans) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}