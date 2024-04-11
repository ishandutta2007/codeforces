#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector <vector <int> > gr;
vector <int> cnt, color;

int now = 0;

void dfs(int v, int col) {
	if (color[v] != -1) return;
	now++;
	color[v] = col;
	for (int u : gr[v]) {
		dfs(u, col);
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	gr.resize(n);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int k;
		cin >> k;
		int v;
		if (k) {
			cin >> v;
			v--;
		}
		for (int j = 1; j < k; j++) {
			int u;
			cin >> u;
			u--;
			gr[v].push_back(u);
			gr[u].push_back(v);
		}
	}
	color.resize(n, -1);
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] != -1) continue;
		now = 0;
		dfs(i, last++);
		cnt.push_back(now);
	}
	for (int i = 0; i < n; i++) {
		cout << cnt[color[i]] << " ";
	}
	cout << "\n";
}