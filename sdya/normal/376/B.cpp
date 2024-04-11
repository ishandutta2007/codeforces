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

const int maxN = 110;
int n, m;
int a[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> m;
	int res = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u - 1][v - 1] += w;
		res += w;
	}

	for (int i = 0; i < n; ++i) {
		int A = 0, B = 0;
		for (int j = 0; j < n; ++j) {
			A += a[i][j];
			B += a[j][i];
		}
		res -= min(A, B);
	}
	cout << res << endl;

	return 0;
}