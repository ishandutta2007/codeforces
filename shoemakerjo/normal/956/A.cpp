#include <bits/stdc++.h>

using namespace std;
#define maxn 52

bool visr[maxn], visc[maxn];

vector<int> adjr[maxn];
vector<int> adjcol[maxn];
bool ans;
vector<int> cr, cl; //current values

void dfsrow(int u);

void dfscol(int u) {
	visc[u] = true;
	cl.push_back(u);
	for (auto v : adjcol[u]) {
		if (!visr[v]) dfsrow(v);
	}
}

void dfsrow(int u) {
	visr[u] = true;
	cr.push_back(u);
	for (auto v : adjr[u]) {
		if (!visc[v]) dfscol(v);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	bool grid[n][m];
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = line[j] == '#';
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j]) {
				adjr[i].push_back(j);
				adjcol[j].push_back(i);
			}
		}
	}
	fill(visr, visr+maxn, false);
	fill(visc, visc+maxn, false);
	ans = true;
	for (int i = 0; i < n; i++) {
		if (!visr[i]) {
			cr.clear();
			cl.clear();
			dfsrow(i);
			for (auto v : cr) {
				for (auto u : cl) {
					if (!grid[v][u]) ans = false;
				}
			}
		}
	}

	if (ans) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	cin >> n;

}