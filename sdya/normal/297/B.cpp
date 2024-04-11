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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, k;
	map < int, int > M;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);
		++M[v];
	}
	for (int i = 1; i <= m; ++i) {
		int v;
		scanf("%d", &v);
		--M[v];
	}

	int total = 0;
	while (!M.empty()) {
		int t = M.rbegin()->first;
		if (M[t] == 0) {
			M.erase(M.find(t));
			continue;
		}
		if (M[t] < 0) {
			total -= M[t];
			M.erase(M.find(t));
			continue;
		}
		int d = min(total, M[t]);
		total -= d;
		M[t] -= d;
		if (M[t] > 0) {
			printf("YES\n");
			return 0;
		}
		M.erase(M.find(t));
	}

	printf("NO\n");

	return 0;
}