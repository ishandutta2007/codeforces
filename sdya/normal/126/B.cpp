#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

const int maxN = 1100000;

int n;
char s[maxN];
int z[maxN];

void z_function() {
	for (int i = 1, l = 0, r = 0; i < n; i ++) {
		if (i <= r)	z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	n = strlen(s);
	z_function();

	int best = 0;
	for (int i = 1; i < n; i ++)
		if (i + z[i] - 1 < n - 1) best = max(best, z[i]); else
			best = max(best, z[i] - 1);

	int res = 0;
	for (int i = 1; i < n; i ++)
		if (i + z[i] - 1 == n - 1) {
			if (z[i] <= best)
				res = max(res, z[i]);
		}

	if (res == 0) {
		printf("Just a legend\n");
		return 0;
	}
	for (int i = 0; i < res; i ++)
		printf("%c", s[i]);
	printf("\n");

	return 0;
}