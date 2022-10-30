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

const int maxN = 110000;
int n;
int a[maxN], p[maxN];
vector < int > g[maxN];
int s;

long long d[maxN];
bool used[maxN];

void dfs(int v) {
	used[v] = true;
	vector < pair < long long, int > > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
			children.push_back(make_pair(d[g[v][i]], g[v][i]));
		}
	}

	sort(children.rbegin(), children.rend());
	int candidates = a[v];
	if (v != s) {
		--candidates;
	}

	int oldCandidates = candidates;
	candidates = min(candidates, (int)(children.size()));

	long long left = 0;
	long long res = 0;
	for (int i = 0; i < candidates && i < children.size(); ++i) {
		res += children[i].first;
		left += p[children[i].second];
	}
	for (int i = candidates; i < children.size(); ++i) {
		left += a[children[i].second];
	}

	long long have = oldCandidates - candidates;
	res += 2 * candidates;
	res += 2LL * min(have, left);
	p[v] = oldCandidates - candidates - min(have, left);
	d[v] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d", &s);

	dfs(s);

	cout << d[s] << endl;

	return 0;
}