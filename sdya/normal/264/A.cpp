#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
char s[maxN];
int n, L[maxN], R[maxN];

void dfs(int v) {
	if (v > n) {
		return ;
	}

	if (L[v]) {
		dfs(L[v]);
	}
	printf("%d\n", v);
	if (R[v]) {
		dfs(R[v]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'l') {
			L[i + 1] = i + 2;
		} else {
			R[i + 1] = i + 2;
		}
	}

	dfs(1);
	return 0;
}