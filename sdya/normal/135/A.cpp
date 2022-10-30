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

const int maxN = 110000;
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (a[n - 1] != 1) {
		a[n - 1] = 1;
	} else {
		a[n - 1] = 2;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}