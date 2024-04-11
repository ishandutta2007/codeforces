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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, a[maxN], b[maxN];
int pos[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		pos[b[i]] = i;
	}

	int current = 0;
	for (int i = 1; i <= n; ++i) {
		if (pos[a[i]] < current) {
			printf("%d\n", n - i + 1);
			return 0;
		}
		current = max(current, pos[a[i]]);
	}

	printf("0\n");

	return 0;
}