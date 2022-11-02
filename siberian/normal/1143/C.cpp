#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 1e5 + 10;
int n;
vector <int> g[MAXN];
int color[MAXN];
int root;
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, c;
		cin >> p >> c;
		color[i] = c;
		if (p == -1) {
			root = i;
			continue;
		}
		p--;
		g[i].push_back(p);
		g[p].push_back(i);
	}
}


vector <int> ans;


void dfs(int v, int p) {
	int sz = 0;
	int cnt = 0;
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v);
			cnt += color[i];
			sz++;
		}
	}
	if (sz == cnt && color[v] == 1) {
		ans.push_back(v + 1);
	} 
}

void run() {
	dfs(root, root);
	sort(ans.begin(), ans.end());
}

void write() {
	if (ans.size() == 0)
		ans.push_back(-1);
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
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