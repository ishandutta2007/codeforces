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

const int maxN = 1100;
int m = 2;
bool g[maxN][maxN];

void addEdge(int u, int v) {
	g[u][v] = g[v][u] = true;
}

void buildPath(int s, int t, int k, int len) {
	if (len <= 0) {
		cerr << "Bad!!!" << endl;
		return;
	}
	if (k == 1) {
		int p = s;
		for (int i = 1; i < len; ++i) {
			int v = ++m;
			addEdge(p, v);
			p = v;
		}
		addEdge(p, t);
		return;
	}

	int v1 = ++m;
	int v2 = ++m;
	int v3 = ++m;
	addEdge(s, v1);
	addEdge(s, v2);
	addEdge(v2, v3);
	addEdge(v1, v3);
	if (k % 2 == 1) {
		buildPath(s, t, 1, len);
	}
	buildPath(v3, t, k / 2, len - 2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	buildPath(1, 2, n, 60);
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (g[i][j]) {
				printf("Y");
			} else {
				printf("N");
			}
		}
		printf("\n");
	}


	return 0;
}