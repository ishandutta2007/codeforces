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
int n, m;
int d[maxN], h[maxN];
long long s[maxN];
long long a[maxN], b[maxN];

vector < pair < long long, int > > ta[4 * maxN], tb[4 * maxN];

vector < pair < long long, int > > merge(vector < pair < long long, int > > &a, vector < pair < long long, int > > &b) {
	vector < pair < long long, int > > res(a.size() + b.size());
	merge(a.rbegin(), a.rend(), b.rbegin(), b.rend(), res.rbegin());
	if (res.size() > 2) {
		res.resize(2);
	}
	return res;
}

void build(vector < pair < long long, int > > t[], long long a[], int i, int l, int r) {
	if (l == r) {
		t[i] = vector < pair < long long, int > > (1, make_pair(a[l], l));
		return;
	}
	build(t, a, 2 * i, l, (l + r) / 2);
	build(t, a, 2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = merge(t[2 * i], t[2 * i + 1]);
}

vector < pair < long long, int > > getValue(vector < pair < long long, int > > t[], int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return getValue(t, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return getValue(t, 2 * i, l, (l + r) / 2, cl, cr);
	}
	vector < pair < long long, int > > a = getValue(t, 2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	vector < pair < long long, int > > b = getValue(t, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return merge(a, b);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
		d[i + n] = d[i];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
		h[i + n] = h[i];
	}

	for (int i = 0; i < n + n; ++i) {
		s[i] = d[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	for (int i = 0; i < n + n; ++i) {
		a[i] = (i == 0 ? 0LL : s[i - 1]) + 2LL * h[i];
		b[i] = (i == 0 ? 0LL : -s[i - 1]) + 2LL * h[i];
	}

	build(ta, a, 1, 0, 2 * n - 1);
	build(tb, b, 1, 0, 2 * n - 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		if (u > v) {
			v += n;
		}

		vector < pair < int, int > > segments;
		segments.push_back(make_pair(u - n, v - n));
		segments.push_back(make_pair(u, v));
		segments.push_back(make_pair(u + n, v + n));
		long long score = 0;
		for (int j = 1; j < 3; ++j) {
			int l = segments[j - 1].second + 1;
			int r = segments[j].first - 1;
			if (l < 0) {
				l = 0;
			}
			if (r >= 2 * n) {
				r = 2 * n - 1;
			}
			if (l < r) {
				vector < pair < long long, int > > a = getValue(ta, 1, 0, 2 * n - 1, l, r);
				vector < pair < long long, int > > b = getValue(tb, 1, 0, 2 * n - 1, l, r);
				for (int x = 0; x < a.size(); ++x) {
					for (int y = 0; y < b.size(); ++y) {
						if (a[x].second != b[y].second) {
							score = max(score, a[x].first + b[y].first);
						}
					}
				}
			}
		}
		printf("%I64d\n", score);
	}


	return 0;
}