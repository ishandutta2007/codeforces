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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x1, y1, x2, y2;
	scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
	int p = x1 - x2;
	int q = y1 - y2;
	if (p < 0) p = -p;
	if (q < 0) q = -q;
	++p;
	++q;

	if (p <= 5 && q <= 5 && p + q <= 8) {
		printf("First\n");
	} else {
		printf("Second\n");
	}

	return 0;
}