//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

int mark[N], col[N], ecolor[N], sz[N], cc, belong[N], act[N], rev[N];

vector<pair<int, int>> adj[N];
int flag = 0;
void dfs(int v, int comp, int kk = 1, int p = -1, int c = 0) {
//	cout << v << ' ' << c << endl;
	if (mark[v] && col[v] != c) {
		flag++;
		return;
	}
	if (mark[v])
		return;
	mark[v] = 1;
	act[comp] += c;
	sz[comp]++;
	col[v] = c;
	belong[v] = comp;
	for (auto e : adj[v]) {
		int u = e.first, id = e.second;
		if (kk == flag)
			return;
		if (u != p)
			dfs(u, comp, kk, v, ecolor[id] ^ c ^ 1);
	}
	
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		char c; cin >> c;
		ecolor[i] = (c == 'R');
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	
	rep(v, n) if (!mark[v]) {
		dfs(v, cc, 1);
		if (sz[cc] - act[cc] <= act[cc])
			rev[cc] = 1;
		if (flag)
			break;
		cc++;
	}
	int cnt = 0;
	vector<int> f;
	rep(v, n)
		if (rev[belong[v]] ^ col[v] || flag)
			f.push_back(v + 1);
	memset(act, 0, sizeof act);
	memset(sz, 0, sizeof sz);
	memset(rev, 0, sizeof rev);
	memset(col, 0, sizeof col);
	memset(mark, 0, sizeof mark);
	memset(belong, 0, sizeof belong);
	cc = 0;
	rep(e, m)
		ecolor[e] ^= 1;
	int temp = flag;
	rep(v, n) if (!mark[v]) {
		dfs(v, cc, temp + 1);
		if (sz[cc] - act[cc] <= act[cc])
			rev[cc] = 1;
		if (flag != temp)
			break;
		cc++;
	}
	vector<int> s;
	rep(v, n)
		if (rev[belong[v]] ^ col[v] || flag != temp)
			s.push_back(v + 1);
	if (s.size() < f.size())
		swap(s, f);
	if (flag == 2) {
		cout << -1;
		return 0;
	}
	cout << (int) f.size() << '\n';
	for (auto x : f)
		cout << x  << ' ';
}