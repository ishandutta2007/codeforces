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

int n;

void process(vector < vector < int > > a) {
	vector < vector < int > > answers(a.size(), vector < int > (n, 0));
	for (int i = 0; i < a.size(); ++i) {
		printf("%d\n", a[i].size());
		for (int j = 0; j < a[i].size(); ++j) {
			if (j != 0) {
				printf(" ");
			}
			printf("%d", a[i][j] + 1);
		}
		printf("\n");
		fflush(stdout);


		for (int j = 0; j < n; ++j) {
			scanf("%d", &answers[i][j]);
		}
	}

	printf("-1\n");
	for (int i = 0; i < n; ++i) {
		int res = 1000000000;
		for (int j = 0; j < a.size(); ++j) {
			if (binary_search(a[j].begin(), a[j].end(), i)) {
				continue;
			}
			res = min(res, answers[j][i]);
		}
		if (i != 0) {
			printf(" ");
		}
		printf("%d", res);
	}
	printf("\n");
	fflush(stdout);
}

bool isOk(vector < vector < int > > a) {
	for (int i = 0; i < a.size(); ++i) {
		sort(a[i].begin(), a[i].end());
	}
	bool isgood = true;
	for (int i = 0; i < n && isgood; ++i) {
		vector < bool > used(n, false);
		for (int j = 0; j < a.size(); ++j) {
			if (binary_search(a[j].begin(), a[j].end(), i)) {
				continue;
			}
			for (int k = 0; k < a[j].size(); ++k) {
				used[a[j][k]] = true;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (i != j && !used[j]) {
				isgood = false;
			}
		}
	}
	return isgood;
}

vector < vector < int > > steps;

void solve(int n, int m) {
	for (int len = 1; len <= m / 2; len *= 2) {
		vector < int > c;
		for (int i = 0; i < m; i += 2 * len) {
			for (int j = i; j < i + len; ++j) {
				if (j < n) {
					c.push_back(j);
				}
			}
		}
		if (c.size() > 0) {
			steps.push_back(c);
		}
		c.clear();
		for (int i = len; i < m; i += 2 * len) {
			for (int j = i; j < i + len; ++j) {
				if (j < n) {
					c.push_back(j);
				}
			}
		}
		if (c.size() > 0) {
			steps.push_back(c);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	solve(n, 1024);
	//cerr << isOk(steps) << endl;
	process(steps);


	return 0;
}