#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;

using namespace __gnu_cxx;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e5L + 11;
vector <int> e[N];

int n;

int pr[N], sz[N];
void dfs1(int x, int p) {
	pr[x] = p; sz[x] = 1;
	for(int i : e[x]) if(i != p) {
		dfs1(i, x);
		sz[x] += sz[i];
	}
}

vector <pair <int, pair <int, int>>> ans;

int nxt[N][2];
rope <int> r[N], ir[N];

void dfs2(int x, int p) {
	int sc = 0;
	for(int i : e[x]) if(i != p) {
		sc ++;
		dfs2(i, x);
	}
	if(!sc) {
		r[x] = ir[x] = {x};
	} else {
		r[x] = ir[x] = {x}; int l = p;
		vector <int> v;
		for(int i : e[x]) if(i != p) {
			v.pb(i);
		}
		r[x] = ir[v[0]]; ir[x] = r[v[0]]; ans.pb({p, {x, ir[v[0]][0]}}); l = r[v[0]][0];
		for(int i = 1; i < v.size(); i ++) {
			ans.pb({l, {x, ir[v[i]][0]}});
			r[x] = r[x] + ir[v[i]];
			ir[x] = r[v[i]] + ir[x];
			l = ir[x][0];
		}
		r[x] += x;
		ir[x] = rope<int>{x} + ir[x];
	}
}

void solve(rope <int> r, int p) {
	vi v;
	//cout << "!\n"; for(int x : r) cout << x << ' '; cout << '\n';
	for(int x : r) v.pb(x);
	for(int i = (int)v.size() - 2; i >= 0; i --)
		ans.pb({v[i], {v[i + 1], v.back()}});
	ans.pb({p, {v[0], v.back()}});
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		e[u].pb(v); e[v].pb(u);
	}
	
	dfs1(1, 0);
	
	int r = -1;
	for(int i = 1; i <= n; i ++) {
		bool f = 1;
		for(int s : e[i]) if(s != pr[i])
			if(sz[s] * 2 >= n) f = 0;
		if((n - sz[i]) * 2 >= n) f = 0;
		if(f) r = i;
	}
	
	//cout << r << '\n';
	
	if(r != -1) {
		for(int i : e[r]) {
			dfs2(i, r); solve(::r[i], r);
		}
	} else {
		for(int i = 2; i <= n; i ++) if(sz[i] * 2 == n) {
			for(int j : e[i]) if(j != pr[i]) {
				dfs2(j, i); solve(::r[j], i);
			}
			for(int j : e[pr[i]]) if(j != i) {
				dfs2(j, pr[i]); solve(::r[j], pr[i]);
			}
			break;
		}
	}
	
	auto v = ans; ans = {};
	for(auto p : v) if(p.sec.fir != p.sec.sec) ans.pb(p);
	cout << ans.size() << '\n';
	for(auto p : ans)
		cout << p.fir << ' ' << p.sec.fir << ' ' << p.sec.sec << '\n';
	
	return 0;
}