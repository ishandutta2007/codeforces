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

const int maxN = 110000;
int s[3][maxN];
char c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &c);
	int n = strlen(c);
	string t = "xyz";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			s[j][i] = (c[i] == t[j]);
			if (i > 0) {
				s[j][i] += s[j][i - 1];
			}
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		int x = s[0][r] - (l == 0 ? 0 : s[0][l - 1]);
		int y = s[1][r] - (l == 0 ? 0 : s[1][l - 1]);
		int z = s[2][r] - (l == 0 ? 0 : s[2][l - 1]);
		bool isOk = (r - l + 1 < 3);
		if (x == y && x == z) {
			isOk = true;
		}
		if (x == y + 1 && x == z + 1) {
			isOk = true;
		}
		if (x == z + 1 && y == z + 1) {
			isOk = true;
		}
		if (y == z + 1 && y == x + 1) {
			isOk = true;
		}
		if (y == x + 1 && z == x + 1) {
			isOk = true;
		}
		if (z == x + 1 && z == y + 1) {
			isOk = true;
		}
		if (z == y + 1 && x == y + 1) {
			isOk = true;
		}
		if (isOk) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}