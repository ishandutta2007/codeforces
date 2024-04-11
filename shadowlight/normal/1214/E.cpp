#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
vector <pair <int, int> > d;
vector <int> dd;
vector <vector <int> > gr;

void add_edge(int v, int u) {
	cout << v << " " << u << "\n";
	v--, u--;
	//gr[v].push_back(u);
	//gr[u].push_back(v);
}

int dfs(int v, int p, int h, int t) {
	if (v == t) return h;
	int sum = 0;
	for (int u : gr[v]) {
		if (u == p) continue;
		sum += dfs(u, v, h + 1, t);
	}
	return sum;
}

void check_gr() {
	for (int i = 0; i < n; i++) {
		int now = dfs(2 * i, -1, 0, 2 * i + 1);
		if (now != dd[i]) {
			assert(false);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].first;
		dd.push_back(d[i].first);
		d[i].second = i;
	}
	sort(d.rbegin(), d.rend());
	vector <int> line(d[0].first + 1);
	vector <vector <int> > nei(d[0].first + 1);
	line[0] = 2 * d[0].second + 1;
	line.back() = 2 * d[0].second + 2;
	int now = 0;
	int sz = line.size() - 1;
	for (int now = 1; now < sz; now++) {
		int v = now, sz = d[now].first;
		int nxt = d[now].first + now;
		line[v] = 2 * d[now].second + 1;
		if (nxt >= line.size()) {
			line.push_back(2 * d[now].second + 2);
			nei.push_back({});
		} else {
			nei[nxt - 1].push_back(2 * d[now].second + 2);
		}
	}
	vector <pair <int, int> > edges;
	//cout << line.size() << "\n";
	for (int i = sz; i < n; i++) {
		int a = 2 * d[i].second + 1, b = 2 * d[i].second + 2; 
		nei[0].push_back(a);
		if (d[i].first == 1) {
			edges.push_back({a, b});
		} else {
			nei[d[i].first - 2].push_back(b);
		}
	}
	gr.resize(2 * n);
	for (int i = 0; i < (int) line.size(); i++) {
		int x = line[i];
		if (i < (int) line.size() - 1) {
			add_edge(x, line[i + 1]);
		}
		for (int y : nei[i]) {
			add_edge(x, y);
		}
	}
	for (auto e : edges) {
		add_edge(e.first, e.second);
	}
	//check_gr();
}