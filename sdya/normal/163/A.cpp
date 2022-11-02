#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 1000000007;
const int maxN = 5100;

int d[maxN][maxN];
char s1[maxN], s2[maxN];
int n, m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s1);
	gets(s2);
	n = strlen(s1);
	m = strlen(s2);
	for (int i = 0; i <= n; ++i)
		d[i][0] = 1;
	for (int i = 0; i <= m; ++i)
		d[0][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				d[i][j] += d[i - 1][j - 1];
				if (d[i][j] >= P) d[i][j] -= P;
			}
			d[i][j] += d[i][j - 1];
			if (d[i][j] >= P) d[i][j] -= P;
		}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += d[i][m];
		if (res >= P) res -= P;
	}
	res -= n;
	res = ((res % P) + P) % P;
	printf("%d\n", res);
	return 0;
}