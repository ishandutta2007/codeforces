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

const int P = 1000000007;
const int maxN = 110000;
int n, q, t;
int a[maxN];
int u = 0, v = 1;
int d[2][maxN];

void update(vector < int > s) {
	for (int i = 0; i < s.size(); ++i, swap(u, v)) {
		memset(d[v], 0, sizeof(d[v]));
		for (int j = 0; j < maxN; ++j) {
			if (i + 1 < s.size()) {
				d[v][j] = (j >= s[i] ? d[u][j - s[i]] : 0);
			} else {
				d[v][j] = d[u][j];
			}
			if (j >= s[i]) {
				d[v][j] += d[v][j - s[i]];
				if (d[v][j] >= P) {
					d[v][j] -= P;
				}
			}
		}
	}
}

int p[maxN], dg[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		p[u] = v;
		++dg[v];
	}

	int cnt = 0;
	d[u][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (dg[i] == 0) {
			vector < int > path;
			int j = i;
			while (j) {
				path.push_back(j);
				j = p[j];
			}

			vector < int > s(path.size());
			for (int k = 0; k < path.size(); ++k) {
				s[k] = a[path[k]];
				if (k > 0) {
					s[k] += s[k - 1];
				}
			}
			update(s);
			cnt += path.size();
		}
	}
	
	if (cnt != n) {
		printf("%d\n", 0);
		return 0;
	} else {
		printf("%d\n", d[u][t]);
	}


	return 0;
}