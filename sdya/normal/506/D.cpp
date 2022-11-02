#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 101000;
const int maxD = 250;
vector < pair < int, int > > g[maxN];
int n, m;

vector < int > v[maxN];
vector < int > p[maxN];
vector < pair < int, int > > edges[maxN];

int cnt[maxN];

pair < int, int > a[maxN], b[maxN];

bitset < maxN > t[2000];
int t_cnt;

int findSet(vector < int > &p, int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = findSet(p, p[v]);
}

void merge(vector < int > &p, int x, int y) {
	x = findSet(p, x);
	y = findSet(p, y);
	if (x == y) {
		return;
	}
	if (rand() % 2 == 0) {
		p[x] = y;
	} else {
		p[y] = x;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		edges[w].push_back(make_pair(x, y));
		v[w].push_back(x);
		v[w].push_back(y);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
		if (a[i].first > a[i].second) {
			swap(a[i].first, a[i].second);
		}
		b[i] = a[i];
	}

	sort(b, b + q);
	int nq = unique(b, b + q) - b;

	for (int i = 1; i <= m; ++i) {
		sort(v[i].begin(), v[i].end());
		v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());

		p[i].resize(v[i].size());
		for (int j = 0; j < v[i].size(); ++j) {
			p[i][j] = j;
		}
		for (int j = 0; j < edges[i].size(); ++j) {
			int x = lower_bound(v[i].begin(), v[i].end(), edges[i][j].first) - v[i].begin();
			int y = lower_bound(v[i].begin(), v[i].end(), edges[i][j].second) - v[i].begin();
			merge(p[i], x, y);
		}
		vector < pair < int, int > > current(v[i].size());
		for (int j = 0; j < v[i].size(); ++j) {
			current[j].first = findSet(p[i], p[i][j]);
			current[j].second = v[i][j];
		}
		sort(current.begin(), current.end());
		int l = 0;
		for (int j = 1; j <= current.size(); ++j) {
			if (j == current.size() || current[j].first > current[j - 1].first) {
				int r = j - 1;
				if (r - l + 1 < maxD) {
					for (int x = l; x <= r; ++x) {
						for (int y = x + 1; y <= r; ++y) {
							int u = current[x].second;
							int v = current[y].second;
							if (u > v) {
								swap(u, v);
							}
							int id = lower_bound(b, b + nq, make_pair(u, v)) - b;
							if (id == nq || b[id] != make_pair(u, v)) {
								continue;
							}
							++cnt[id];
						}
					}
				} else {
					for (int x = l; x <= r; ++x) {
						t[t_cnt][current[x].second] = 1;
					}
					++t_cnt;
				}
				l = j;
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int id = lower_bound(b, b + nq, a[i]) - b;
		int res = cnt[id];

		for (int j = 0; j < t_cnt; ++j) {
			if (t[j][a[i].first] && t[j][a[i].second]) {
				++res;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}