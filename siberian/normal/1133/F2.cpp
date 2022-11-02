#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 2 * 1e5 + 10;
vector <int> g[MAXN];
int n, m, d;
bool used[MAXN];
int tin[MAXN], fup[MAXN], timer = 0;
vector <pair <int, int> > ans;
int pred[MAXN];

int par(int v) {
	if (v == pred[v])
		return v;
	return pred[v] = par(pred[v]);
}

void un(int a, int b) {
	a = par(a);
	b = par(b);
	if (a != b) 
		pred[a] = b;
}

vector <int> ed;

void read() {
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a > b)
			swap(a, b);
		if (a == 0) {
			ed.push_back(b);
			continue;
		}
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		pred[i] = i;
}
int comps[MAXN];
int comp;
void dfs(int v) {
	comps[v] = comp;
	for (auto i : g[v]) {
		if (!comps[i])
			dfs(i);
	} 
}

void run() {
	for (int i = 1; i < n; i++) {
		if (!comps[i]) {
			comp++;
			dfs(i);
		}
	}

	for (auto i : ed) {
		if (!used[comps[i]]) {
			ans.push_back({i, 0});
			used[comps[i]] = 1;
			un(i, 0);
		}
	}
	
	for (int i = 1; i <= comp; i++) {
		if (!used[i]) {
			cout << "NO" << endl;
			exit(0);
		}
	}

	int cnt;
	cnt = comp;
	
	//cout << "cnt = " << cnt << " " << "d = " << d << endl << endl << par(0) << endl;;
	for (auto i : ed) {
	//	cout << i << " " << par(i) << endl;
		if (par(i) != par(0) && cnt < d){
			un(i, 0);
			ans.push_back({i, 0});
			cnt++;
		}
	}
	if (cnt != d) {
		cout << "NO" << endl;
		exit(0);
	}
	//cout << "cnt = " << cnt << " " << "d = " << d << endl;
	for (int i = 1; i < n; i++) {
		for (auto j : g[i]) {
		    if (j == 0)
		    continue;
			if (par(i) != par(j)){
				ans.push_back({i, j});
				un(i, j);
			}
		}
	}
}

void write() {
	cout << "YES" << endl;
	for (auto i : ans){
		cout << i.first + 1 << " " << i.second + 1 << '\n';
	}
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