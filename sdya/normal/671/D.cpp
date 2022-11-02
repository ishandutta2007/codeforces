#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
int n, m, d[maxN];
vector < int > g[maxN];
vector < pair < int, int > > p[maxN];
long long c[maxN];

set < pair < int, long long > > *S[maxN];
int added[maxN];
long long cost[maxN];

void dfs(int v, int p = -1, int depth = 0) {
	d[v] = depth;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != p) {
			dfs(g[v][i], v, depth + 1);
		}
	}
}

bool comp(int x, int y) {
	return S[x]->size() > S[y]->size();
}

void add(set < pair < int, long long > > &S, int added, long long cost, int len, long long price) {
	if (len < 0) {
		return;
	}
	pair < int, long long > p(len - added, price - cost);
	S.insert(p);

	while (true) {
		set < pair < int, long long > > ::iterator it = S.find(p);
		if (it == S.end()) {
			break;
		}

		set < pair < int, long long > > ::iterator rt = it;
		++rt;
		if (rt != S.end() && rt->second <= it->second) {
			S.erase(it);
			break;
		}

		set < pair < int, long long > > ::iterator lt = it;
		if (lt != S.begin()) {
			--lt;
			if (lt->second >= it->second) {
				S.erase(lt);
				continue;
			}
			if (lt->first == it->first) {
				S.erase(it);
				break;
			}
		}
		break;
	}
}

long long calc(int v, int parent = -1) {
	vector < int > children;
	long long res = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			res += calc(g[v][i], v);
			children.push_back(g[v][i]);
		}
	}

	if (children.size() == 0) {
		S[v] = new set < pair < int, long long > > ();
		for (int i = 0; i < p[v].size(); ++i) {
			add(*S[v], 0, 0, p[v][i].first, p[v][i].second);
		}
		added[v] = 0;
		cost[v] = 0;
		return c[v] = 0;
	}

	sort(children.begin(), children.end(), comp);

	S[v] = S[children[0]];
	cost[v] = cost[children[0]];
	added[v] = added[children[0]] - 1;

	while (!S[v]->empty() && S[v]->begin()->first + added[v] < 0) {
		S[v]->erase(S[v]->begin());
	}

	if (S[v]->empty()) {
		printf("-1\n");
		exit(0);
	}

	long long reduced = S[v]->begin()->second + cost[v];
	res += reduced;
	cost[v] -= reduced;

	for (int t = 1; t < children.size(); ++t) {
		int u = children[t];
		while (!S[u]->empty() && S[u]->begin()->first + added[u] - 1 < 0) {
			S[u]->erase(S[u]->begin());
		}
		if (S[u]->empty()) {
			printf("-1\n");
			exit(0);
		}
		long long reduced = S[u]->begin()->second + cost[u];
		res += reduced;
		cost[u] -= reduced;

		for (set < pair < int, long long > > ::iterator it = S[u]->begin(); it != S[u]->end(); ++it) {
			int len = it->first + added[u] - 1;
			long long price = it->second + cost[u];
			add((*S[v]), added[v], cost[v], len, price);
		}
	}

	for (int i = 0; i < p[v].size(); ++i) {
		add((*S[v]), added[v], cost[v], p[v][i].first, p[v][i].second);
	}
	
	return c[v] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u;
		--v;
		p[u].push_back(make_pair(d[u] - d[v], c));
	}

	cout << calc(0) << endl;



	return 0;
}