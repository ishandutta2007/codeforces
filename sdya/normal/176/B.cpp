#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;

char s1[maxN], s2[maxN];
int n, k;
int good[maxN];

int d[2][maxN], s[2];
const int P = 1000000007;

int u, v;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s1);
	gets(s2);
	scanf("%d", &k);
	n = strlen(s1);
	for (int i = 0; i < n; ++i) {
		good[i] = true;
		for (int j = i; j < i + n; ++j)
			if (s1[j % n] != s2[j - i]) good[i] = false;
	}

	u = 0, v = 1;
	d[u][0] = 1;
	s[u] = 1;
	for (int step = 0; step < k; step ++, swap(u, v)) {
		for (int i = 0; i < n; ++i)
			d[v][i] = 0;
		s[v] = 0;
		for (int i = 0; i < n; ++i) {
			d[v][i] = s[u] - d[u][i];
			if (d[v][i] < 0) d[v][i] += P;
			if (d[v][i] >= P) d[v][i] -= P;
			s[v] += d[v][i];
			if (s[v] >= P) s[v] -= P;
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i)
		if (good[i]) {
			res += d[u][i];
			if (res >= P) res -= P;
		}
	printf("%d\n", res);

	return 0;
}