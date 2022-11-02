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

const int maxN = 110000;

vector < int > byx[maxN];
vector < int > byy[maxN];

unordered_set < int > s[maxN];

int x[maxN], y[maxN];

bool exists(int x, int y) {
	return s[x].find(y) != s[x].end();
}

void gen() {
	int n = 315 * 315;
	printf("%d\n", n);
	for (int i = 0; i < 315; ++i) {
		for (int j = 0; j < 315; ++j) {
			printf("%d %d\n", i, j);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		byx[x[i]].push_back(y[i]);
		byy[y[i]].push_back(x[i]);
		s[x[i]].insert(y[i]);
	}

	for (int i = 0; i < maxN; ++i) {
		sort(byx[i].begin(), byx[i].end());
		sort(byy[i].begin(), byy[i].end());
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int px = lower_bound(byx[x[i]].begin(), byx[x[i]].end(), y[i]) - byx[x[i]].begin();
		int py = lower_bound(byy[y[i]].begin(), byy[y[i]].end(), x[i]) - byy[y[i]].begin();

		int nx = byx[x[i]].size() - px;
		int ny = byy[y[i]].size() - py;

		if (nx < ny) {
			for (int j = px + 1; j < byx[x[i]].size(); ++j) {
				int d = byx[x[i]][j] - y[i];
				if (exists(x[i] + d, y[i]) && exists(x[i] + d, y[i] + d)) {
					++res;
				}
			}
		} else {
			for (int j = py + 1; j < byy[y[i]].size(); ++j) {
				int d = byy[y[i]][j] - x[i];
				if (exists(x[i], y[i] + d) && exists(x[i] + d, y[i] + d)) {
					++res;
				}
			}
		}
	}

	printf("%d\n", res);
	//cerr << clock() << endl;

	return 0;
}