// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 706, mod = (int) 0;
map<vector<int>, int> save;
int tot = 0, col[N];
vector<int> cur;
int ask(vector<int> s) {
	sort(ALL(s));
	s.resize(unique(ALL(s)) - s.begin());
	if ((int) s.size() <= 1) return 0;
	if (save.find(s) != save.end()) return save[s];
	tot++;
	if (tot >= 19999) assert(0);
	int res;
	cout << "? " << (int) s.size() << endl;
	for (int x : s) cout << (x + 1) << ' ';
	cout << endl;
	cin >> res;
	assert(res != -1);
	return save[s] = res;
}
vector<int> merge(vector<int> x, vector<int> y) {
	for (int p : y) x.pb(p);
	return x;
}
pair<int, int> find_edge(vector<int> s, vector<int> t) {
	if (s.size() == 1 && t.size() == 1) {
		assert(ask(merge(s, t)));
		return mp(s[0], t[0]);	
	}
	if ((int) s.size() == 1) {
		int sx = ask(s);
		vector<int> x, y;
		for (int j = 0; j < (int) t.size(); ++j) {
			if (j < (int) t.size() / 2) {
				x.pb(t[j]);
			} else {
				y.pb(t[j]);
			}
		}
		int xx = ask(x);
		int mx = ask(merge(x, s));
		if (mx - sx - xx > 0) {
			return find_edge(s, x);	
		} else {
			return find_edge(s, y);
		}
	} else {
			
		int tx = ask(t);
		vector<int> x, y;
		for (int j = 0; j < (int) s.size(); ++j) {
			if (j < (int) s.size() / 2) {
				x.pb(s[j]);
			} else {
				y.pb(s[j]);
			}
		}
		int xx = ask(x);
		int mx = ask(merge(x, t));
		if (mx - tx - xx > 0) {
			return find_edge(x, t);	
		} else {
			return find_edge(y, t);
		}
	}
}
int res[N], tp;
vector<int> adj[N];
int dfs(int x, int p, int dest, int cnt = 0) {
	if (dest == x) {
		assert((cnt + 1) >= 3);
		assert((cnt + 1) % 2 == 1);
		res[tp++] = dest;
//		cout << (cnt + 1) << endl;
//		cout << dest + 1 << ' ';
		return 1;
	}
	for (int u : adj[x]) if (u != p) {
		if (dfs(u, x, dest, cnt + 1)) {
//			cout << x + 1 << ' ';
			res[tp++] = x;
			return 1;
		}
	}
	return 0;
	
}
int mat[N][N];
pair<int, int> find_edge(vector<int> a) {
	if ((int) a.size() == 2) {
		return mp(a[0], a[1]);	
	}
	int x = a.back();
	a.pop_back();
	if (ask(a)) {
		return find_edge(a);	
	}
	vector<int> s;
	s.pb(x);
	return find_edge(s, a);
}
int main() {
	int n;
	cin >> n;
	col[0] = 1;
	cur.pb(0);
	for (int j = 0; j < n - 1; ++j) {
		vector<int> rest;
		for (int i = 0; i < n; ++i)
			if (!col[i])
				rest.pb(i);
		auto e = find_edge(cur, rest);
		col[e.y] = 3 - col[e.x];
		cur.pb(e.y);
		adj[e.x].pb(e.y);
		adj[e.y].pb(e.x);
		mat[e.x][e.y] = mat[e.y][e.x] = 1;
	}
	vector<int> fp, sp;
	for (int j = 0; j < n; ++j) {
		assert(col[j]);
		if (col[j] == 1)
			fp.pb(j);
		else
			sp.pb(j);
	}
	if (ask(fp) == 0 && ask(sp) == 0) {
		cout << "Y " << (int) fp.size() << endl;
		for (int x : fp) cout << (x + 1) << ' '; 
		cout << endl;
		return 0;
	}
	pair<int, int> e = mp(-1, -1);;
	if (ask(fp) != 0) {
		e = find_edge(fp);
	} else {
		assert(ask(sp));
		e = find_edge(sp);
	}
	vector<int> a;
	assert(e.x != -1);
	assert(e.x != e.y);
	assert(col[e.x] == col[e.y]);
	a.pb(e.x);
	a.pb(e.y);
	assert(ask(a));
	assert(dfs(e.x, -1, e.y));
	cout << "N " << tp << endl;
	for (int j = 0; j < tp; ++j) {
		vector<int> wtf;
		wtf.pb(res[j]);
		wtf.pb(res[(j + 1) % tp]);
		assert(ask(wtf));
	}
	assert(tp >= 3);
	assert(tp % 2 == 1);
	for (int j = tp - 1; j >= 0; --j) 
		cout << res[j] + 1 << ' ';
	cout << endl;
	
}