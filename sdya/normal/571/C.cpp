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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 510000;
int n, m;
vector < int > a[maxN];
vector < pair < int, int > > pos[maxN];

set < pair < int, int > > S;

bool isSet[maxN];
int res[maxN];

void erase(int id, int value) {
	int a = abs(value);
	S.erase(make_pair(pos[a].size(), a));
	pos[a].erase(find(pos[a].begin(), pos[a].end(), make_pair(id, value)));
	S.insert(make_pair(pos[a].size(), a));
}

void update(int index) {
	if (isSet[index]) {
		return;
	}
	isSet[index] = true;
	for (int i = 0; i < a[index].size(); ++i) {
		int value = a[index][i];
		erase(index, value);
	}
}

vector < pair < int, int > > g[maxN];
bool used[maxN];
int edge;
int root;
vector < int > comp;

void dfs(int v, int id = -1) {
	used[v] = true;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == id) {
			continue;
		}
		if (!used[g[v][i].second]) {
			dfs(g[v][i].second, g[v][i].first);
			continue;
		}

		root = v;
		edge = i;
	}
}

void setValue(int id, int v) {
	for (int i = 0; i < pos[id].size(); ++i) {
		if (pos[id][i].first == v) {
			res[id] = (pos[id][i].second > 0 ? 1 : 0);
			isSet[v] = true;
			return;
		}
	}
}

void setUp(int v, int id = -1) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == id) {
			continue;
		}
		if (v == root && edge == i) {
			continue;
		}
		if (!used[g[v][i].second]) {
			setValue(g[v][i].first, g[v][i].second);
			setUp(g[v][i].second, g[v][i].first);
			continue;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		res[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		a[i].assign(k, 0);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &a[i][j]);
			pos[abs(a[i][j])].push_back(make_pair(i, a[i][j]));
		}
		isSet[i] = false;
	}

	for (int i = 1; i <= m; ++i) {
		sort(pos[i].begin(), pos[i].end());
		pos[i].resize(unique(pos[i].begin(), pos[i].end()) - pos[i].begin());
	}

	for (int i = 1; i <= m; ++i) {
		map < int, vector < int > > M;
		for (int j = 0; j < pos[i].size(); ++j) {
			M[pos[i][j].first].push_back(pos[i][j].second);
		}

		for (map < int, vector < int > >::iterator it = M.begin(); it != M.end(); ++it) {
			int id = it->first;
			vector < int > a = it->second;
			sort(a.begin(), a.end());
			if (a.size() > 1) {
				update(id);
			}
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (pos[i].size() == 0) {
			res[i] = 1;
			continue;
		}
		if (pos[i].size() != 2) {
			continue;
		}
		if (pos[i][0].second < 0 && pos[i][1].second < 0) {
			res[i] = 0;
			int x = pos[i][0].first;
			int y = pos[i][1].first;
			update(x);
			update(y);
			continue;
		}
		if (pos[i][0].second > 0 && pos[i][1].second > 0) {
			res[i] = 1;
			int x = pos[i][0].first;
			int y = pos[i][1].first;
			update(x);
			update(y);
			continue;
		}

		if (pos[i][0].first == pos[i][1].first) {
			res[i] = 1;
			update(pos[i][0].first);
			continue;
		}
	}

	S.clear();
	for (int i = 1; i <= m; ++i) {
		if (res[i] != -1) {
			continue;
		}
		S.insert(make_pair(pos[i].size(), i));
	}

	while (!S.empty()) {
		pair < int, int > p = *S.begin();
		if (res[p.second] != -1) {
			S.erase(S.begin());
			continue;
		}
		if (p.first == 0) {
			res[p.second] = 1;
			S.erase(S.begin());
			continue;
		}
		if (p.first == 2) {
			break;
		}
		S.erase(S.begin());

		int v = p.second;
		if (pos[v][0].second > 0) {
			res[v] = 1;
		} else {
			res[v] = 0;
		}
		update(pos[v][0].first);
	}

	for (int i = 1; i <= m; ++i) {
		if (res[i] != -1) {
			continue;
		}
		int u = pos[i][0].first;
		int v = pos[i][1].first;
		g[u].push_back(make_pair(i, v));
		g[v].push_back(make_pair(i, u));
	}

	for (int i = 0; i < n; ++i) {
		if (isSet[i]) {
			continue;
		}
		edge = -1;
		root = -1;
		comp.clear();
		dfs(i);
		if (root == -1) {
			printf("NO\n");
			return 0;
		}
		for (int j = 0; j < comp.size(); ++j) {
			used[comp[j]] = false;
		}
		setUp(root);
		setValue(g[root][edge].first, root);
	}

	printf("YES\n");
	for (int i = 1; i <= m; ++i) {
		if (res[i] == -1) {
			res[i] = 1;
		}
		printf("%d", res[i]);
	}
	printf("\n");

	return 0;
}