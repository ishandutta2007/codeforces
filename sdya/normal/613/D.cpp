#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

int n, m;
vector < int > g[maxN];
vector < int > q[maxN];
unordered_set < int > sq;
unordered_map < int, int > *S[maxN];
int added[maxN];

int res[maxN];
bool bad[maxN];

bool comp(int x, int y) {
	return S[x]->size() > S[y]->size();
}

void dfs(int v, int p = -1) {
	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != p) {
			dfs(g[v][i], v);
			children.push_back(g[v][i]);
		}
	}

	sort(children.begin(), children.end(), comp);
	if (children.size() == 0) {
		S[v] = new unordered_map < int, int > ();
		added[v] = 0;
		for (int i = 0; i < q[v].size(); ++i) {
			(*S[v])[q[v][i]] = 0;
		}
		return;
	}

	sq.clear();
	unordered_set < int > marked;
	for (int i = 0; i < q[v].size(); ++i) {
		sq.insert(q[v][i]);
		if (S[children[0]]->count(q[v][i])) {
			int len = (*S[children[0]])[q[v][i]] + added[children[0]];
			if (len == 0) {
				bad[q[v][i]] = true;
			}
			marked.insert(q[v][i]);
			++res[q[v][i]];
		}
	}

	for (int i = 1; i < children.size(); ++i) {
		int u = children[i];
		for (unordered_map < int, int > ::iterator it = S[u]->begin(); it != S[u]->end(); ++it) {
			if (it->second + added[u] == 0 && sq.count(it->first)) {
				bad[it->first] = true;
			}
			if (sq.count(it->first)) {
				marked.insert(it->first);
				++res[it->first];
			}
		}
	}

	S[v] = S[children[0]];
	added[v] = added[children[0]] + 1;

	for (int i = 1; i < children.size(); ++i) {
		int u = children[i];
		for (unordered_map < int, int > ::iterator it = S[u]->begin(); it != S[u]->end(); ++it) {
			if (bad[it->first] || marked.count(it->first)) {
				continue;
			}

			int q = it->first;
			int len = it->second + added[u] + 1;

			if (S[v]->count(q)) {
				if (marked.count(q) == 0) {
					++res[q];
					marked.insert(q);
				}
				S[v]->erase(q);
			} else {
				(*S[v])[q] = len - added[v];
			}
		}
	}

	for (int i = 0; i < q[v].size(); ++i) {
		(*S[v])[q[v][i]] = -added[v];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int u;
			scanf("%d", &u);
			--u;
			q[u].push_back(i);
		}
	}

	dfs(0);

	for (int i = 0; i < m; ++i) {
		if (bad[i]) {
			printf("-1\n");
		} else {
			printf("%d\n", res[i]);
		}
	}


	return 0;
}