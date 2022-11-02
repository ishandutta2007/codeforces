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

const int maxN = 510000;
int n;
vector < int > g[maxN], w[maxN];
unordered_map < int, int > *s[maxN];
int shift[maxN], len[maxN];
int res[maxN];

void dfs(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
		res[v] = max(res[v], res[g[v][i]]);
	}

	if (g[v].size() == 0) {
		s[v] = new unordered_map < int, int > ();
		(*s[v])[0] = 0;
		shift[v] = 0;
		res[v] = 0;
		return ;
	}

	int best = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (s[g[v][i]]->size() > s[g[v][best]]->size()) {
			best = i;
		}
	}

	s[v] = s[g[v][best]];
	shift[v] = shift[g[v][best]];
	shift[v] ^= (1 << w[v][best]);
	len[v] = len[g[v][best]];
	++len[v];

	for (int i = 0; i < g[v].size(); ++i) {
		if (i == best) {
			continue;
		}
		int u = g[v][i];
		int c = w[v][i];

		shift[u] ^= (1 << c);
		++len[u];
		for (unordered_map < int, int > ::iterator it = s[u]->begin(); it != s[u]->end(); ++it) {
			int current = (shift[v] ^ shift[u] ^ (it->first));
			int l = len[u] + len[v] + it->second;
			unordered_map < int, int > ::iterator jt = s[v]->find(current);
			if (jt != s[v]->end()) {
				res[v] = max(res[v], jt->second + l);
			}
			for (int j = 0; j <= 'v' - 'a'; ++j) {
				jt = s[v]->find(current ^ (1 << j));
				if (jt != s[v]->end()) {
					res[v] = max(res[v], jt->second + l);
				}
			}
		}
		for (unordered_map < int, int > ::iterator it = s[u]->begin(); it != s[u]->end(); ++it) {
			int current = (shift[u] ^ shift[v] ^ it->first);
			int value = it->second + len[u] - len[v];
			if (s[v]->count(current)) {
				(*s[v])[current] = max((*s[v])[current], value);
			} else {
				(*s[v])[current] = value;
			}
		}
	}

	unordered_map < int, int > ::iterator it = s[v]->find(shift[v]);
	if (it != s[v]->end()) {
		res[v] = max(res[v], it->second + len[v]);
	}
	for (int j = 0; j <= 'v' - 'a'; ++j) {
		it = s[v]->find(shift[v] ^ (1 << j));
		if (it != s[v]->end()) {
			res[v] = max(res[v], len[v] + it->second);
		}
	}
	if (s[v]->count(shift[v])) {
		(*s[v])[shift[v]] = max((*s[v])[shift[v]], -len[v]);
	} else {
		(*s[v])[shift[v]] = -len[v];
	}
}

void gen() {
	int n = 500000;
	printf("%d\n", n);
	for (int i = 1; i < n; ++i) {
		printf("%d %c\n", i, rand() % 21 + 'a');
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	//return 0;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v;
		char c;
		scanf("%d %c", &v, &c);
		g[v].push_back(i + 1);
		w[v].push_back(c - 'a');
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");

	//cerr << clock() << endl;

	return 0;
}