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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
const int inf = 1000000000;
int d[maxN][maxN];
int n;
int a[maxN], s[maxN];

struct Q {
	deque < int > maxs;
	void push(int value) {
		while (!maxs.empty() && value > maxs.back()) {
			maxs.pop_back();
		}
		maxs.push_back(value);
	}

	void pop(int value) {
		if (value == maxs.front()) {
			maxs.pop_front();
		}
	}

	int get() {
		return maxs.front();
	}
};

void init(int d[]) {
	for (int i = 0; i < maxN; ++i) {
		d[i] = -inf;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 0; i < maxN; ++i) {
		init(d[i]);
	}

	for (int i = 1; i <= n; ++i) {
		d[i][1] = 1;
	}
	for (int j = 2; j <= n; ++j) {
		int bound = j - 1;
		int value = d[j - 1][j - 1];
		for (int i = j; i <= n; ++i) {
			int totalSum = s[i] - s[j - 1];
			while (bound - 1 > 0 && s[j - 1] - s[bound - 2] <= totalSum) {
				value = max(value, d[j - 1][bound - 1]);
				--bound;
			}
			if (s[j - 1] - s[bound - 1] <= totalSum) {
				d[i][j] = value + 1;
			}
		}
	}

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res = max(res, d[n][i]);
	}
	printf("%d\n", n - res);

	return 0;
}