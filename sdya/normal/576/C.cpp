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

const int maxN = 1100000;
int x[maxN], y[maxN];
int n;

const int maxK = 2000;
vector < int > groups[maxK];

bool comp(int u, int v) {
	return make_pair(x[u], y[u]) < make_pair(x[v], y[v]);
}

int getRand() {
	int value = rand() * rand() + rand();
	value %= 1000000;
	if (value < 0) {
		value = -value;
	}
	return value;
}

void gen() {
	int n = 1000000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", getRand(), getRand());
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		groups[y[i] / 1013].push_back(i);
	}

	for (int i = 0; i < maxK; ++i) {
		sort(groups[i].begin(), groups[i].end(), comp);
		if (i % 2 == 1) {
			reverse(groups[i].begin(), groups[i].end());
		}
	}

	//vector < int > order;
	for (int i = 0; i < maxK; ++i) {
		for (int j = 0; j < groups[i].size(); ++j) {
			printf("%d ", groups[i][j]);
			//order.push_back(groups[i][j]);
		}
	}
	printf("\n");

	/*long long total = 0;
	for (int i = 0; i + 1 < order.size(); ++i) {
		total += abs(x[order[i]] - x[order[i + 1]]) + abs(y[order[i]] - y[order[i + 1]]);
	}
	cerr << total << endl;*/

	return 0;
}