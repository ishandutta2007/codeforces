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

const int maxN = 210000;
vector < int > g[maxN];
int n;
char s[maxN];

bool isValid(int x) {
	return 0 <= x && x < n;
}

bool used[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%s", &s);
	vector < int > starts;
	for (int i = 0; i < n; ++i) {
		int j = (s[i] == '>' ? (i + 1) : (i - 1));
		if (isValid(j)) {
			g[j].push_back(i);
		} else {
			starts.push_back(i);
		}
	}

	for (int i = 0; i < starts.size(); ++i) {
		dfs(starts[i]);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			++res;
		}
	}
	printf("%d\n", res);


	return 0;
}