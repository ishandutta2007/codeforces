#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int n;
vector < int > g[maxN];
bool used[maxN];
vector < int > order;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
	order.push_back(v);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		if (p != -1) {
			g[p].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	vector < int > dp(n + 1);
	for (int i = 0; i < n; ++i) {
		int v = order[i];
		dp[v] = 1;
		for (int j = 0; j < g[v].size(); ++j) {
			dp[v] = max(dp[v], dp[g[v][j]] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
	
	return 0;
}