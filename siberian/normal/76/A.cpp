#include <bits/stdc++.h>

using namespace std;
#define int long long

struct edge{
	int u, v, gold, silver;
	edge() {
		u = v = gold = silver = -1;
	}
	edge(int a, int b, int c, int d) {
		u = a, v = b, gold = c, silver = d;
	}
};

bool cmp(edge a, edge b) {
	return a.gold < b.gold;
}

const int MAXN = 210, INF = 2*1e18 + 10;
set<pair <int, int> > gr[MAXN];
int comps;
int ans = INF;

int n, m, gold, silver;
vector<edge> g;

void read() {
	cin >> n >> m >> gold >> silver;
	for (int i = 0; i < m; i++) {
		edge help;
		cin >> help.u >> help.v >> help.gold >> help.silver;
		help.u--;
		help.v--;
		g.push_back(help);
	}
	sort(g.begin(), g.end(), cmp);
}

pair <bool, edge> max_help(pair <bool, edge> a, pair <bool, edge> b) {
	if (!a.first && b.first)
		swap(a, b);
	if (a.first != b.first)
		return a;
	if (a.second.silver > b.second.silver)
		return a;
	return b;
}

pair <bool, edge> get_edge(int v, int p, int cost, int need) {
	if (need == v) return {true, edge(v, p, 0, cost)};
	pair <bool, edge> ans = {false, edge(v, p, 0, cost)};

	for (auto i : gr[v]) {
		if (i.first != p) {
			pair <bool, edge> help = get_edge(i.first, v, i.second, need);
			ans.first |= help.first;
			if (help.first)
				ans = max_help(ans, help);
		}
	}
	return ans;
}

pair <bool, edge> get_edge(int v, int u) {
	pair <bool, edge> ans = {false, {}};
	for (auto i : gr[v]) {
		ans = max_help(ans, get_edge(i.first, v, i.second, u));
	}
	return ans;
}

void add(edge a) {
	int u = a.u;
	int v = a.v;
	int s = a.silver;

	auto check = gr[v].lower_bound({u, -1});
	if (check != gr[v].end()) {
		int u1 = check->first;
		int s1 = check->second;
		if (u1 == u) {
			if (s < s1) {
				gr[v].erase({u, s1});
				gr[u].erase({v, s1});

				gr[v].insert({u, s});
				gr[u].insert({v, s});
			}
			return;
		}
	}

	auto help = get_edge(u, v);
	//cerr << "help = " << help.first << " " << help.second.u << " " << help.second.v << " " << help.second.silver << endl;  
	if (!help.first) {
		gr[u].insert({v, s});
		gr[v].insert({u, s});
		comps--;
		return;
	}

	if (s < help.second.silver) {
		int v1 = help.second.v;
		int u1 = help.second.u;
		int s1 = help.second.silver;

		gr[u1].erase({v1, s1});
		gr[v1].erase({u1, s1});

		gr[u].insert({v, s});
		gr[v].insert({u, s});
		return;
	}
}

int get_max(int v, int p, int cost) {
	int ans = cost;
	for (auto i : gr[v]) {
		if (i.first != p) {
			ans = max(ans, get_max(i.first, v, i.second));
		}
	}
	return ans;
}

int get_max() {
	return get_max(0, -1, 0);
}

int get_ans(int cnt_gold) {
	if (comps > 1) return INF;
	int cnt_silver = get_max();
	return cnt_gold * gold + cnt_silver * silver;
}

void print() {
	//cerr << "gr = " << endl;
	for (int i = 0; i < n; i++) {
		//cerr << "i = " << i << endl;
		for (auto j : gr[i]){
			//cerr << j.first << " " << j.second << endl;
		}
	}
	//cerr << endl;	
}

void run() {
	comps = n;
	//cerr << "g = " << endl;
	for (auto i : g) {
		//cerr << i.u << " " << i.v << " " << i.gold << " " << i.silver << endl;
	} 


	print();
	for (int i = 0; i < m; i++) {
		if (g[i].u == g[i].v) continue;
		add(g[i]);
		//cerr << "g[i] = " << g[i].u << " " << g[i].v << " " << g[i].gold << " " << g[i].silver << endl;
		print();
		ans = min(ans, get_ans(g[i].gold));
		//cerr << "ans = " << ans << endl;
	}
}

void write() {
	if (ans == INF) ans = -1;
	cout << ans << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}