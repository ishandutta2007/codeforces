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

const int maxN = 110000;
int n, p[maxN];

bool used[maxN];

vector < vector < int > > cycles[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		vector < int > cycle;
		int j = i;
		while (!used[j]) {
			cycle.push_back(j);
			used[j] = true;
			j = p[j];
		}
		cycles[cycle.size()].push_back(cycle);
	}

	if (cycles[1].size() > 0) {
		int v = cycles[1][0][0];
		printf("YES\n");
		for (int i = 1; i <= n; ++i) {
			if (i != v) {
				printf("%d %d\n", v, i);
			}
		}
		return 0;
	}

	if (cycles[2].size() == 0) {
		printf("NO\n");
		return 0;
	}
	for (int i = 3; i <= n; ++i) {
		if (i % 2 == 1 && cycles[i].size() > 0) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	printf("%d %d\n", cycles[2][0][0], cycles[2][0][1]);
	for (int i = 0; i + 1 < cycles[2].size(); ++i) {
		printf("%d %d\n", cycles[2][i][0], cycles[2][i + 1][0]);
		printf("%d %d\n", cycles[2][i][1], cycles[2][i + 1][1]);
	}

	for (int i = 3; i <= n; ++i) {
		for (int j = 0; j < cycles[i].size(); ++j) {
			for (int k = 0; k < cycles[i][j].size(); k += 2) {
				int x = cycles[i][j][k];
				int y = cycles[i][j][k + 1];
				printf("%d %d\n", cycles[2][0][0], x);
				printf("%d %d\n", cycles[2][0][1], y);
			}
		}
	}

	return 0;
}