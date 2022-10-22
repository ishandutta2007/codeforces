#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 1e9 + 7;

struct Edge {
	int v, u, c;
};

vector <Edge> edges;
int n, m;
vector <vector <pair <int, int> > > gr;

vector <int> used;
vector <Edge> cycle_edge;

vector <vector <pair <int, int> > > tree;
vector <int> d;

void dfs(int v, int p = -1) {
	used[v] = 1;
	for (auto e : gr[v]) {
		int u = e.x;
		if (u == p) continue;
		if (used[u]) continue;
		d[u] = d[v] ^ e.y;
		dfs(u, v);
	}
}

vector <int> values;

void color_dfs(int v, int p = -1) {
	used[v] = 2;
	for (auto e : gr[v]) {
		int u = e.x;
		if (u == p) continue;
		if (used[u] == 2) {
			//cout << u << " " << v << endl;
			values.push_back(d[v] ^ d[u] ^ e.y);
		} else if (used[u] < 2) {
			color_dfs(u, v);
		}
	}
	used[v] = 3;
}

map <ll, int> mask_num;
int now = 0;

const int N = 407;

int edge[N][32];

int dp[N], ndp[N];

void rec(vector <int> &a, ll mask = 1) {
	if (mask_num.count(mask)) return;
	int num = now++;
	mask_num[mask] = num;
	for (int i = 0; i < 32; i++) {
		edge[num][i] = -1;
		ll nmask = mask;
		int sz = a.size();
		bool good = true;
		for (int j = 0; j < (1 << sz); j++) {
			int now = i;
			for (int d = 0; d < sz; d++) {
				if ((1 << d) & j) {
					now ^= a[d];
				}
			}
			if (nmask & (1LL << now)) {
				good = false;
				break;
			}
			nmask |= (1LL << now);
		}
		if (!good) continue;
		a.push_back(i);
		rec(a, nmask);
		a.pop_back();
		edge[num][i] = mask_num[nmask];
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
	if (x < 0) {
		x += MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector <int> V;
	rec(V);

	cin >> n >> m;
	gr.resize(n);
	used.resize(n, 0);
	vector <bool> inc(n, false);
	vector <int> w(n, -1);
	vector <int> pe(n, -1);
	vector <int> we(n, -1);
	d.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int v, u, c;
		cin >> v >> u >> c;
		v--, u--;
		if (v > u) swap(v, u);
		if (!v) {
			inc[u] = true;
			w[u] = c;
		}
		edges.push_back({v, u, c});
	}
	for (int i = 0; i < m; i++) {
		int v = edges[i].v, u = edges[i].u, c = edges[i].c;
		if (!v) {
			continue;
		}
		if (inc[v] && inc[u]) {
			pe[v] = u, we[v] = c;
			pe[u] = v, we[u] = c;
		}
		gr[v].push_back({u, c});
		gr[u].push_back({v, c});
	}
	dp[0] = 1;
	for (int v = 0; v < n; v++) {
		if (used[v] || !inc[v]) continue;
		//cout << "V: " << v << " " << pe[v] << endl;
		values.clear();
		dfs(v, -1);
		color_dfs(v, -1);
		// cout << values.size() << endl;
		/*for (int x : values) {
			cout << x << " ";
		}
		cout << "\n";
		*/
		fill(ndp, ndp + N, 0);
		for (int num = 0; num < now; num++) {
			int nxt = num;
			for (int x : values) {
				if (nxt == -1) break;
				nxt = edge[nxt][x];
			}
			add(ndp[num], dp[num]);

			if (nxt == -1) continue;
			add(ndp[nxt], dp[num]); 
			
			if (pe[v] == -1) continue;
			
			add(ndp[nxt], dp[num]); 
			int u = pe[v];
			int wnow = w[v] ^ w[u] ^ we[v];
			int a = edge[nxt][wnow];
			if (a != -1) add(ndp[a], dp[num]);
		}
		swap(dp, ndp);
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		add(res, dp[i]);
	}
	cout << res << "\n";
}