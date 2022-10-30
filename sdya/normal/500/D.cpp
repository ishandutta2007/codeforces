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

const int maxN = 510000;
int n;
vector < int > g[maxN];
int a[maxN], b[maxN], l[maxN];
long long cnt[maxN];
bool used[maxN];

int s[maxN];

void dfs(int v, int parent = -1) {
	used[v] = true;
	++s[v];
	for (int i = 0; i < g[v].size(); ++i) {
		int index = g[v][i];
		int u = a[index];
		if (u == v) {
			u = b[index];
		}
		if (used[u]) {
			continue;
		}
		dfs(u, index);
		s[v] += s[u];
	}
	if (parent != -1) {
		cnt[parent] = (long long)(s[v]) * (long long)(n - s[v]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &l[i]);
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	dfs(1);
	long long score = 0;
	for (int i = 1; i < n; ++i) {
		score += (long long)(cnt[i]) * (long long)(l[i]);
	}

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int index, value;
		scanf("%d%d", &index, &value);
		score -= (long long)(cnt[index]) * (long long)(l[index]);
		l[index] = value;
		score += (long long)(cnt[index]) * (long long)(l[index]);
		long double res = (long double)(score) * 6.0;
		res /= (long double)(n);
		res /= (long double)(n - 1);
		printf("%.12lf\n", (double)(res));
	}
	
	return 0;
}