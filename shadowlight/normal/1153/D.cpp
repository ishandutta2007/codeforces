#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector <int> mx, tp, all;
vector <vector <int> > gr;

void dfs(int v) {
	for (int u : gr[v]) {
		dfs(u);
	}
	if (!gr[v].size()) {
		mx[v] = 0;
		all[v] = 1;
	} else {
		int cnt = 0, mink = n;
		//cout << v << "\n";
		for (int u : gr[v]) {
			cnt += mx[u];
			all[v] += all[u];
			mink = min(mink, all[u] - mx[u]);
		}
		if (tp[v]) {
			cnt = all[v] - mink;
		}
		mx[v] = cnt;
		//cout << mx[v] << "\n";
	}
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	gr.resize(n);
	mx.resize(n);
	all.resize(n);
	tp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tp[i];
	}
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		gr[p].push_back(i);
	}
	dfs(0);
	cout << mx[0] + 1 << "\n";
}