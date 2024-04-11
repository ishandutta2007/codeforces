#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct edge{
	int v, u, cost;
};

bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int n, m, k;
vector<edge> g;

void read() {
	cin >> n >> m >> k;
	g.resize(m);
	for (auto &i : g){
		cin >> i.v >> i.u >> i.cost;
		i.v--;
		i.u--;
	}
	sort(g.begin(), g.end(), cmp);
	g.resize(k);
}

const int MAXN = 810;
int d[MAXN][MAXN];
int ans;

void run() {
	set<int> need;
	for (auto i : g) {
		need.insert(i.u);
		need.insert(i.v);
	}

	int cnt = 0;
	map <int, int> coord;
	for (auto i : need)
		coord[i] = cnt++;

	n = cnt;

	for (auto &i : g) {
		i.u = coord[i.u];
		i.v = coord[i.v];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = 1e18;

	for (auto i : g) {
		d[i.u][i.v] = i.cost;
		d[i.v][i.u] = i.cost;
	}

	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	vector<int> fout;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			fout.push_back(d[i][j]);
		}
	}

	sort(fout.begin(), fout.end());
	ans = fout[k - 1];
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}