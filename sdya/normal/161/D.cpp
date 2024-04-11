#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 60000;

map < int, int > * M[maxN];
int add[maxN];
vector < int > g[maxN];
bool used[maxN];
int n, k;
long long res = 0;

bool comp(int x, int y) {
	return M[x]->size() > M[y]->size();
}

void dfs(int v) {
	if (used[v]) return ;
	used[v] = true;

	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i)
		if (!used[g[v][i]]) {
			children.push_back(g[v][i]);
			dfs(g[v][i]);
		}

	if (children.size() == 0) {
		M[v] = new map < int, int > ;
		M[v]->insert(make_pair(0, 1));
		add[v] = 0;
		return ;
	}

	sort(children.begin(), children.end(), comp);
	M[v] = M[children[0]];
	add[v] = add[children[0]] + 1;
	for (int i = 1; i < children.size(); ++i) {
		int u = children[i];
		for (map < int, int > :: iterator j = M[u]->begin(); j != M[u]->end(); ++j) {
			int length = j->first + add[u] + 1;
			if (M[v]->count(k - length - add[v]) != 0)
				res += (long long)(M[v]->find(k - length - add[v])->second) * (long long)(j->second);
		}

		for (map < int, int > :: iterator j = M[u]->begin(); j != M[u]->end(); ++j) {
			int length = j->first + add[u] + 1 - add[v];
			if (M[v]->count(length) == 0) {
				M[v]->insert(make_pair(length, j->second));
			} else {
				map < int, int > :: iterator x = M[v]->find(length);
				int value = x->second + j->second;
				M[v]->erase(x);
				M[v]->insert(make_pair(length, value));
			}
		}
	}

	if (M[v]->count(k - add[v]) != 0) {
		res += (long long)(M[v]->find(k - add[v])->second);
	}
	M[v]->insert(make_pair(-add[v], 1));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << res << endl;
	return 0;
}