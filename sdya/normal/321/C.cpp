#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
vector < int > g[maxN];
int n;

int used[maxN], cnt;
int d[maxN];

int killed[maxN];

int findCenter(int v) {
	++cnt;
	queue < int > q;
	q.push(v);
	d[v] = 0;
	int best = v;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		used[u] = cnt;
		for (int i = 0; i < g[u].size(); ++i) {
			if (killed[g[u][i]] || used[g[u][i]] == cnt) {
				continue;
			}
			used[g[u][i]] = cnt;
			d[g[u][i]] = d[u] + 1;
			if (d[g[u][i]] > d[best]) {
				best = g[u][i];
			}
			q.push(g[u][i]);
		}
	}

	++cnt;
	v = best;
	d[v] = 0;
	q.push(v);
	vector < int > ver;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		used[u] = cnt;
		ver.push_back(u);
		for (int i = 0; i < g[u].size(); ++i) {
			if (killed[g[u][i]] || used[g[u][i]] == cnt) {
				continue;
			}
			used[g[u][i]] = cnt;
			d[g[u][i]] = d[u] + 1;
			if (d[g[u][i]] > d[best]) {
				best = g[u][i];
			}
			q.push(g[u][i]);
		}
	}

	int needed = d[best] / 2;
	for (int i = 0; i < ver.size(); ++i) {
		if (d[ver[i]] == needed) {
			return ver[i];
		}
	}
}

int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	set < int > unmarked;
	unmarked.insert(1);

	int position = 0;
	while (!unmarked.empty()) {
		set < int > newLevel;
		for (set < int > ::iterator it = unmarked.begin(); it != unmarked.end(); ++it) {
			if (killed[*it]) {
				continue;
			}
			int id = findCenter(*it);
			if (killed[id]) {
				continue;
			}
			res[id] = position;
			if (position >= 26) {
				printf("Impossible!\n");
				return 0;
			}
			killed[id] = true;

			for (int i = 0; i < g[id].size(); ++i) {
				if (!killed[g[id][i]]) {
					newLevel.insert(g[id][i]);
				}
			}
		}

		unmarked = newLevel;
		++position;
	}

	for (int i = 1; i <= n; ++i) {
		printf("%c ", 'A' + res[i]);
	}
	printf("\n");


	return 0;
}