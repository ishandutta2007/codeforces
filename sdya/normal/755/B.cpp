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

const int maxN = 1100;
char s1[maxN][maxN], s2[maxN][maxN];
int n, m;

map < string, int > M;
int cnt = 0;

int getId(string s) {
	if (M.count(s)) {
		return M[s];
	}
	return M[s] = cnt++;
}

int a[maxN], b[maxN];

/*int d[700][700][700];

int calc(int a, int b, int c) {
	if (d[a][b][c] != -1) {
		return d[a][b][c];
	}

	if (a > 0 && calc(a - 1, c, b) == 2) {
		return d[a][b][c] = 1;
	}
	if (b > 0 && calc(a, c, b - 1) == 2) {
		return d[a][b][c] = 1;
	}
	return d[a][b][c] = 2;
}*/

int trivial(int a, int b, int c) {
	if (b + (a % 2) > c) {
		return 1;
	}
	return 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s1[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s", &s2[i]);
	}

	for (int i = 0; i < n; ++i) {
		a[i] = getId(s1[i]);
	}
	for (int i = 0; i < m; ++i) {
		b[i] = getId(s2[i]);
	}

	sort(b, b + m);

	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; ++i) {
		if (binary_search(b, b + m, a[i])) {
			++x;
		} else {
			++y;
		}
	}
	z = m - x;

	if (trivial(x, y, z) == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}