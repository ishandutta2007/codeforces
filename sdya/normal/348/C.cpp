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

const int maxN = 105000;
vector < int > s[maxN];
long long sum[maxN], a[maxN], add[maxN];
int n, m, q;

vector < int > g[maxN];

const int maxD = 350;
int ids[maxD];
bitset < maxN > b[maxD];
int c[maxD][maxD];

int x[maxN][maxD];
int isLong[maxN];

char word[5];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
	}

	vector < pair < int, int > > p;
	for (int i = 1; i <= m; ++i) {
		isLong[i] = -1;
		int k;
		scanf("%d", &k);
		s[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &s[i][j]);
		}
		p.push_back(make_pair(k, i));
	}
	sort(p.rbegin(), p.rend());

	int w = min(maxD, (int)(p.size()));
	for (int i = 0; i < w; ++i) {
		int id = p[i].second;
		for (int j = 0; j < s[id].size(); ++j) {
			b[i][s[id][j]] = 1;
			g[s[id][j]].push_back(i);
			sum[id] += a[s[id][j]];
		}
		ids[i] = id;
		isLong[id] = i;
	}
	for (int i = 0; i < w; ++i) {
		for (int j = i + 1; j < w; ++j) {
			c[i][j] = c[j][i] = (b[i] & b[j]).count();
		}
		c[i][i] = s[ids[i]].size();
	}

	for (int i = 1; i <= m; ++i) {
		if (isLong[i] != -1) {
			continue;
		}
		for (int j = 0; j < s[i].size(); ++j) {
			int u = s[i][j];
			for (int k = 0; k < g[u].size(); ++k) {
				++x[i][g[u][k]];
			}
		}
	}

	for (int t = 0; t < q; ++t) {
		scanf("%s", &word);
		if (word[0] == '?') {
			int k;
			scanf("%d", &k);
			long long res = 0;
			if (isLong[k] == -1) {
				for (int i = 0; i < s[k].size(); ++i) {
					res += a[s[k][i]];
				}
				for (int i = 0; i < w; ++i) {
					res += add[i] * (long long)(x[k][i]);
				}
			} else {
				res = sum[k];
				for (int i = 0; i < w; ++i) {
					res += add[i] * (long long)(c[isLong[k]][i]);
				}
			}
			printf("%I64d\n", res);
		} else {
			int k, delta;
			scanf("%d%d", &k, &delta);
			if (isLong[k] == -1) {
				for (int i = 0; i < s[k].size(); ++i) {
					a[s[k][i]] += delta;
				}
				for (int i = 0; i < w; ++i) {
					sum[ids[i]] += (long long)(delta) * (long long)(x[k][i]);
				}
			} else {
				add[isLong[k]] += delta;
			}
		}
	}


	return 0;
}