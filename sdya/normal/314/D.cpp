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
const long long inf = 1000000000000000000LL;
int n;
long long x[maxN], y[maxN];
int pos[maxN];

long long tMin[4 * maxN];
long long tMax[4 * maxN];

vector < pair < long long, long long > > p;

void build(int i, int l, int r) {
	if (l == r) {
		tMin[i] = inf;
		tMax[i] = -inf;
		return;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	tMin[i] = min(tMin[2 * i], tMin[2 * i + 1]);
	tMax[i] = max(tMax[2 * i], tMax[2 * i + 1]);
}

void update(int i, int l, int r, int k, long long value) {
	if (l == r) {
		tMin[i] = min(tMin[i], value);
		tMax[i] = max(tMax[i], value);
		return;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	tMin[i] = min(tMin[2 * i], tMin[2 * i + 1]);
	tMax[i] = max(tMax[2 * i], tMax[2 * i + 1]);
}

pair < long long, long long > get(int i, int l, int r, int cl, int cr) {
	if (cl > cr) {
		return make_pair(inf, -inf);
	}
	if (l == cl && r == cr) {
		return make_pair(tMin[i], tMax[i]);
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	pair < long long, long long > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	pair < long long, long long > B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return make_pair(min(A.first, B.first), max(A.second, B.second));
}

void precalc() {
	vector < long long > a;
	for (int i = 0; i < n; ++i) {
		a.push_back(x[i]);
		p.push_back(make_pair(x[i], y[i]));
	}
	sort(p.begin(), p.end());
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	build(1, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		pos[i] = lower_bound(a.begin(), a.end(), p[i].first) - a.begin();
		update(1, 0, n - 1, pos[i], p[i].second);
	}
}

bool check(long long d) {
	for (int i = 0; i < p.size(); ++i) {
		int start = upper_bound(p.begin(), p.end(), make_pair(p[i].first + d, inf)) - p.begin();
		pair < long long, long long > A = get(1, 0, n - 1, 0, pos[i] - 1);
		pair < long long, long long > B = make_pair(inf, -inf);
		if (start != p.size()) {
			B = get(1, 0, n - 1, pos[start], n - 1);
		}
		long long L = min(A.first, B.first);
		long long R = max(A.second, B.second);
		if (L + d >= R) {
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		x[i] = u + v;
		y[i] = u - v;
	}

	precalc();

	long long left_bound = 0LL, right_bound = 10000000000LL;
	check(0);
	while (right_bound - left_bound > 1LL) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	long long res = right_bound;
	if (check(left_bound)) {
		res = left_bound;
	}

	printf("%.10lf\n", (double)(res) / 2.0);


	return 0;
}