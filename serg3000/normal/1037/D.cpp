#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
vector<int>used(2 * 100000);
vector<int>par(2 * 100000);
vector<vector<int>>g(2 * 100000, vector<int>(0));
void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int u = g[v][i];
		if (used[u] == 0) {
			par[u] = v;
			used[u] = 1;
			dfs(u);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		b[i] = par[a[i]];
	}
	int j = 0;
	int i = 0;
	if (a[0] != 0) {
		cout << "NO";
		return 0;
	}
	while (i < n) {
		if (j == n) {
			cout << "NO";
			return 0;
		}
		if (b[i] != a[j]) {
			j += 1;
		}
		else {
			i++;
		}
	}
	cout << "YES";
	return 0;
}