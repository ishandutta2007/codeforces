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

const int maxN = 210000;
int s[maxN], r[maxN];
int order[maxN];
int n;

int mx[maxN];

bool comp(int x, int y) {
	return make_pair(s[x], r[x]) < make_pair(s[y], r[y]);
}

double getValue(int i, int j) {
	double A = (double)(r[i] - r[j]) / (double)(r[i] * r[j]);
	double B = (double)(s[i] - s[j]) / (double)(s[i] * s[j]);

	if (s[i] == s[j]) {
		if (r[i] > r[j]) {
			return 1e50;
		} else if (r[i] < r[j]) {
			return -1e50;
		} else {
			return 0;
		}
	}
	return A / B;
}

double getMax(vector < int > &candidates, int pos) {
	if (pos + 1 == candidates.size()) {
		return -1e50;
	}
	int left_bound = pos + 1, right_bound = candidates.size() - 1;
	while (right_bound - left_bound > 10) {
		int m1 = (2 * left_bound + right_bound) / 3;
		int m2 = (left_bound + 2 * right_bound) / 3;

		double v1 = getValue(candidates[pos], candidates[m1]);
		double v2 = getValue(candidates[pos], candidates[m2]);
		if (v1 > v2) {
			right_bound = m2;
		} else {
			left_bound = m1;
		}
	}
	double res = -1e50;
	for (int i = left_bound; i <= right_bound; ++i) {
		double v = getValue(candidates[pos], candidates[i]);
		if (v > 1e40) {
			continue;
		}
		res = max(res, v);
	}
	return res;
}

double getMin(vector < int > &candidates, int pos) {
	if (pos == 0) {
		return 1e50;
	}
	int left_bound = 0, right_bound = pos - 1;
	while (right_bound - left_bound > 10) {
		int m1 = (2 * left_bound + right_bound) / 3;
		int m2 = (left_bound + 2 * right_bound) / 3;

		double v1 = getValue(candidates[pos], candidates[m1]);
		double v2 = getValue(candidates[pos], candidates[m2]);
		if (v1 < v2) {
			right_bound = m2;
		} else {
			left_bound = m1;
		}
	}
	double res = 1e50;
	for (int i = left_bound; i <= right_bound; ++i) {
		double v = getValue(candidates[pos], candidates[i]);
		res = min(res, v);
	}
	return res;
}

void gen() {
	int n = 200000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", rand() % 10000 + 1, rand() % 10000 + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//srand(time(0));
	//gen();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &s[i], &r[i]);
		order[i] = i;
	}
	sort(order, order + n, comp);
	for (int i = n - 1; i >= 0; --i) {
		mx[i] = r[order[i]];
		if (i + 1 < n) {
			mx[i] = max(mx[i], mx[i + 1]);
		}
	}

	vector < int > candidates;
	for (int i = 0; i < n; ++i) {
		if (i + 1 == n || r[order[i]] > mx[i + 1]) {
			candidates.push_back(order[i]);
		}
	}

	vector < int > res;
	set < pair < int, int > > S;
	for (int i = 0; i < candidates.size(); ++i) {
		double A = getMax(candidates, i);
		double B = getMin(candidates, i);

		if (A <= B + 1e-9 && A < 1e-9) {
			S.insert(make_pair(s[candidates[i]], r[candidates[i]]));
		}
	}
	for (int i = 0; i < n; ++i) {
		if (S.count(make_pair(s[i], r[i])) > 0) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

	return 0;
}