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

const int maxN = 1100;
const long long inf = 1000000000000000000LL;
int n, m;
vector < pair < int, long long > > g[maxN];
long long d[maxN][maxN];
long long a[maxN][maxN];
long long dp[maxN];

void calc(int v, long long d[]) {
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	d[v] = 0;
	set < pair < long long, int > > S;
	S.insert(make_pair(d[v], v));
	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first;
			long long length = g[v][i].second;
			if (d[u] > d[v] + length) {
				S.erase(make_pair(d[u], u));
				d[u] = d[v] + length;
				S.insert(make_pair(d[u], u));
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	for (int i = 1; i <= n; ++i) {
		calc(i, d[i]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = inf;
		}
		a[i][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		long long length, cost;
		cin >> length >> cost;
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] <= length) {
				a[i][j] = min(a[i][j], cost);
			}
		}
		dp[i] = inf;
	}

	vector < bool > used(n + 1, false);
	dp[s] = 0;
	for (int i = 0; i < n; ++i) {
		int v = -1;
		long long best = inf;
		for (int j = 1; j <= n; ++j) {
			if (!used[j] && dp[j] < best) {
				best = dp[j];
				v = j;
			}
		}
		if (v == -1) {
			break;
		}

		used[v] = true;
		for (int j = 1; j <= n; ++j) {
			dp[j] = min(dp[j], dp[v] + a[v][j]);
		}
	}

	if (dp[t] >= inf) {
		cout << -1 << endl;
	} else {
		cout << dp[t] << endl;
	}

	
	return 0;
}