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

const int maxN = 25;
int n, m;
int a[maxN], b[maxN];
int index[maxN];
vector < pair < int, int > > p;

int c[maxN];

bool check(int id, int pos) {
	int total = 0;
	for (int i = 0; i < id; ++i) {
		total += m - index[i];
	}
	total += m - pos;
	if (2 * total > n * m) {
		return false;
	}

	for (int r = pos; r < m && r < pos + 100; ++r) {
		int total = 0;
		for (int i = 0; i < id; ++i) {
			if (index[i] < r) {
				total += r - index[i];
			}
		}
		total += r - pos;
		for (int i = 0; i < n; ++i) {
			c[i] = 0;
		}
		for (int i = 0; i < id; ++i) {
			if (index[i] <= r) {
				c[p[i].second] = 1;
			}
		}
		c[p[id].second] = 1;

		for (int i = 0; i < n; ++i) {
			total += c[i];
			if (2 * total > r * n + (i + 1)) {
				return false;
			}
		}
	}
	for (int r = max(pos, m - 100); r < m; ++r) {
		int total = 0;
		for (int i = 0; i < id; ++i) {
			if (index[i] < r) {
				total += r - index[i];
			}
		}
		total += r - pos;
		for (int i = 0; i < n; ++i) {
			c[i] = 0;
		}
		for (int i = 0; i < id; ++i) {
			if (index[i] <= r) {
				c[p[i].second] = 1;
			}
		}
		c[p[id].second] = 1;

		for (int i = 0; i < n; ++i) {
			total += c[i];
			if (2 * total > r * n + (i + 1)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int sA = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sA += a[i];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	sA *= m;
	for (int i = 0; i < n; ++i) {
		p.push_back(make_pair(b[i] - a[i], i));
	}
	sort(p.begin(), p.end());

	int sB = 0;
	for (int i = 0; i < n; ++i) {
		int left_bound = 0, right_bound = m - 1;
		while (right_bound - left_bound > 1) {
			int middle = (left_bound + right_bound) / 2;
			if (check(i, middle)) {
				right_bound = middle;
			} else {
				left_bound = middle;
			}
		}
		int bound = m;
		if (check(i, left_bound)) {
			bound = left_bound;
		} else if (check(i, right_bound)) {
			bound = right_bound;
		}

		sB += p[i].first * (m - bound);
		index[i] = bound;
	}
	long long res = (long long)(sA) + (long long)(sB);
	cout << res << endl;

	return 0;
}