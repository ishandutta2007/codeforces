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
const int inf = 2000000000;
int a[maxN], n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] -= (n - 1 - i);
	}
	sort(a, a + n);
	int current = inf;
	for (int i = n - 1; i >= 0; --i) {
		a[i] += (n - 1 - i);
		if (a[i] < 0 || a[i] > current) {
			printf(":(\n");
			return 0;
		}
		current = a[i];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}