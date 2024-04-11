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

const int maxN = 810000;
int x[maxN], w[maxN], n;
pair < int, int > p[maxN];

int t[4 * maxN], add[4 * maxN];

void update(int i, int l, int r, int cl, int cr, int value) {
	if (l == cl && r == cr) {
		add[i] = 0;
		t[i] = max(t[i], value);
		return;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

int get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return add[i] + get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return add[i] + get(2 * i, l, (l + r) / 2, cl, cr);
	}
	int a = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	int b = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return max(a, b) + add[i];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < int > a;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &w[i]);
		p[i].first = x[i] - w[i];
		p[i].second = x[i] + w[i];
		a.push_back(p[i].first);
		a.push_back(p[i].second);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	int m = a.size();
	for (int i = 0; i < n; ++i) {
		p[i].first = lower_bound(a.begin(), a.end(), p[i].first) - a.begin();
		p[i].second = lower_bound(a.begin(), a.end(), p[i].second) - a.begin();
	}

	sort(p, p + n);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x = get(1, 0, m - 1, 0, p[i].first);
		res = max(res, x + 1);
		update(1, 0, m - 1, p[i].second, p[i].second, x + 1);
	}

	printf("%d\n", res);

	return 0;
}