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

const int maxN = 1200000;
const int maxK = 25;
int a[maxN];
int n;
long long u[maxK], v[maxK];
vector < int > s[4 * maxN];

void precalc(int i, int l, int r, int common = 0) {
	if (l == r) {
		s[i].push_back(a[l]);
		return;
	}
	precalc(2 * i, l, (l + r) / 2, common + 1);
	precalc(2 * i + 1, (l + r) / 2 + 1, r, common + 1);

	s[i].resize(s[2 * i].size() + s[2 * i + 1].size());
	merge(s[2 * i].begin(), s[2 * i].end(), s[2 * i + 1].begin(), s[2 * i + 1].end(), s[i].begin());

	int index = 0;
	for (int j = 0; j < s[2 * i].size(); ++j) {
		while (index < s[2 * i + 1].size() && s[2 * i + 1][index] < s[2 * i][j]) {
			++index;
		}
		u[common] += index;
	}

	index = 0;
	for (int j = 0; j < s[2 * i].size(); ++j) {
		while (index < s[2 * i + 1].size() && s[2 * i + 1][index] <= s[2 * i][j]) {
			++index;
		}
		v[common] += s[2 * i + 1].size() - index;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); ++i) {
		scanf("%d", &a[i]);
	}
	precalc(1, 0, (1 << n) - 1);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int q;
		scanf("%d", &q);
		for (int j = n - q; j <= n; ++j) {
			swap(u[j], v[j]);
		}
		long long res = 0;
		for (int j = 0; j <= n; ++j) {
			res += u[j];
		}
		printf("%I64d\n", res);
	}

	return 0;
}