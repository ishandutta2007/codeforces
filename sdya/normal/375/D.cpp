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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxD = 22;

struct Data {
	vector < vector < int > > parts;
	bool used[maxD];
	int n;
	Data() {
		n = 0;
		parts.resize(maxD);
		for (int i = 0; i < maxD; ++i) {
			used[i] = false;
		}
	}

	void addElement(int value) {
		++n;
		vector < int > current({value});
		for (int i = 0; i < maxD; ++i) {
			if (!used[i]) {
				used[i] = true;
				parts[i] = current;
				break;
			} else {
				vector < int > buf(current.size() * 2);
				merge(current.begin(), current.end(), parts[i].begin(), parts[i].end(), buf.begin());
				parts[i].clear();
				used[i] = false;
				current = buf;
			}
		}
	}

	int getCount(int k) {
		int res = 0;
		int m = n;
		for (int i = 0; i < maxD && m; ++i) {
			if (used[i]) {
				int index = lower_bound(parts[i].begin(), parts[i].end(), k) - parts[i].begin();
				res += parts[i].size() - index;
				m -= (1 << i);
			}
		}
		return res;
	}
};

int n, m;
vector < int > g[maxN];
int color[maxN];

vector < pair < int, int > > q[maxN];
int res[maxN];

Data *add[maxN];
Data *rem[maxN];
unordered_map < int, int > *cnt[maxN];

void addColor(unordered_map < int, int > *cnt, Data *add, Data *rem, int color) {
	int value = (*cnt)[color];
	if (value > 0) {
		rem->addElement(value);
	}
	add->addElement(value + 1);
	++(*cnt)[color];
}

void dfs(int v, int parent = -1) {
	vector < pair < int, int > > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == parent) {
			continue;
		}
		dfs(g[v][i], v);
		children.push_back(make_pair(add[g[v][i]]->n + rem[g[v][i]]->n, g[v][i]));
	}
	sort(children.rbegin(), children.rend());
	if (children.size() == 0) {
		cnt[v] = new unordered_map < int, int > ();
		add[v] = new Data();
		rem[v] = new Data();
	} else {
		int u = children[0].second;
		cnt[v] = cnt[u];
		add[v] = add[u];
		rem[v] = rem[u];

		for (int i = 1; i < children.size(); ++i) {
			int u = children[i].second;
			for (unordered_map < int, int > ::iterator it = cnt[u]->begin(); it != cnt[u]->end(); ++it) {
				for (int j = 0; j < it->second; ++j) {
					addColor(cnt[v], add[v], rem[v], it->first);
				}
			}
		}
	}
	addColor(cnt[v], add[v], rem[v], color[v]);
	for (int i = 0; i < q[v].size(); ++i) {
		res[q[v][i].first] = add[v]->getCount(q[v][i].second) - rem[v]->getCount(q[v][i].second);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &color[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < m; ++i) {
		int v, k;
		scanf("%d%d", &v, &k);
		q[v].push_back(make_pair(i, k));
	}
	dfs(1);

	for (int i = 0; i < m; ++i) {
		printf("%d\n", res[i]);
	}

	return 0;
}