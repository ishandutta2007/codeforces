#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr;

vector <int> sz;

void sz_dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int u : gr[v]) {
		if (u == p) continue;
		sz_dfs(u, v);
		sz[v] += sz[u];
	}
}

map <pair <int, int>, int> values;

void set_edges(int v, int p, vector <int> a) {
	//cout << v << " " << p << " " << a.size() << endl;
	assert(a.size() == sz[v] - 1);
	for (int u : gr[v]) {
		if (u == p) continue;
		int val = a[a.size() - sz[u]];
		vector <int> b;
		for (int i = 0; i < sz[u] - 1; i++) {
			b.push_back(a.back() - val);
			a.pop_back();
		}
		a.pop_back();
		reverse(b.begin(), b.end());
		values[{v, u}] = val;
		set_edges(u, v, b);
	}
}

int n;

const int INF = 1e9 + 7;

const int MAXN = 1e6 + 7;

bool check() {
	vector <vector <pair <int, int> > > gr(n);
	for (auto e : values) {
		int v = e.x.x, u = e.x.y, w = e.y;
		gr[v].push_back({u, w});
		gr[u].push_back({v, w});
	}
	vector <int> have(MAXN);
	for (int i = 0; i < n; i++) {
		queue <int> q;
		vector <int> d(n, INF);
		d[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto e : gr[v]) {
				int u = e.x, w = e.y;
				if (d[u] == INF) {
					d[u] = d[v] + w;
					q.push(u);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			have[d[i]] = true;
		}
	}
	int val = 2 * n * n / 9;
	for (int i = 1; i <= val; i++) {
		if (!have[i]) {
			return false;
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//srand(1337);

	cin >> n;
	gr.resize(n);
	sz.resize(n);
	for (int i = 1; i < n; i++) {
		int v = i + 1, u = rand() % i + 1;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
	}
	int c = -1;
	for (int s = 0; s < n; s++) {
		sz_dfs(s);
		bool is_centroid = true;
		for (int v : gr[s]) {
			if (2 * sz[v] > n) {
				is_centroid = false;
			}
		}
		if (is_centroid) c = s;
	}
	sz_dfs(c);
	vector <bool> can(n, false);
	vector <int> pr(n, -1);
	int lval = (n + 1) / 3, rval = max((n - 1) - lval, lval);
	can[0] = true;
	for (int u : gr[c]) {
		for (int i = n - 1; i >= 0; i--) {
			if (can[i] && !can[i + sz[u]]) {
				can[i + sz[u]] = true;
				pr[i + sz[u]] = u;
				//cout << i << " " << u << " " << sz[u] << endl;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << i << " " << can[i] << " " << pr[i] << " " << sz[pr[i]] << endl;
	}*/
	int opt = -1;
	for (int i = lval; i <= rval; i++) {
		if (can[i]) {
			opt = i;
			break;
		}
	}
	//cout << lval << " " << rval << endl;
	assert(opt != -1);
	//cout << lval << " " << rval << " " << opt << endl;
	vector <int> a(opt), b;
	for (int x = 1; x <= opt; x++) {
		a[x - 1] = x;
	}
	int now = opt + 1;
	for (int i = 0; i < n - 1 - opt; i++) {
		b.push_back(now);
		now += opt + 1;
	}
	vector <bool> in_left(n, false);
	while (opt) {
		//cout << opt << " " << pr[opt] << " " << sz[pr[opt]] << endl;
		in_left[pr[opt]] = true;
		opt -= sz[pr[opt]];
	}
	/*for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
	for (int x : b) {
		cout << x << " ";
	}
	cout << endl;*/
	for (int u : gr[c]) {
		if (in_left[u]) {
			int val = a[a.size() - sz[u]];
			vector <int> d;
			for (int i = 0; i < sz[u] - 1; i++) {
				d.push_back(a.back() - val);
				a.pop_back();
			}
			a.pop_back();
			reverse(d.begin(), d.end());
			values[{c, u}] = val;
			set_edges(u, c, d);
		} else {
			int val = b[b.size() - sz[u]];
			vector <int> d;
			for (int i = 0; i < sz[u] - 1; i++) {
				d.push_back(b.back() - val);
				b.pop_back();
			}
			b.pop_back();
			reverse(d.begin(), d.end());
			values[{c, u}] = val;
			set_edges(u, c, d);
		}
	}
	for (auto e : values) {
		cout << e.x.x + 1 << " " << e.x.y + 1 << " " << e.y << endl; 
	}
	//assert(check());
}