#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

void comp_dfs(vector<vi> &gr, int v, vector<int> &comp, int col) {
	if (comp[v] != -1) return;
	comp[v] = col;
	for (auto w : gr[v]) comp_dfs(gr, w, comp, col);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vi> gr(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gr[a].pb(b), gr[b].pb(a);
	}

	int comp_num = 0;
	vector<int> comp(n, -1);
	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			comp_dfs(gr, i, comp, comp_num);
			comp_num++;
		}
	}

	cout << m - n + comp_num << endl;

	return 0;
}