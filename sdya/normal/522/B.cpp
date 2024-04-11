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
int w[maxN], h[maxN];
int n;
int a[maxN], b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &w[i], &h[i]);
	}

	int s = 0;
	for (int i = 1; i <= n; ++i) {
		s += w[i];
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = max(a[i - 1], h[i]);
	}
	for (int i = n; i >= 1; --i) {
		b[i] = max(b[i + 1], h[i]);
	}

	for (int i = 1; i <= n; ++i) {
		long long A = s - w[i];
		long long B = max(a[i - 1], b[i + 1]);
		long long res = A * B;
		printf("%I64d ", res);
	}
	printf("\n");


	return 0;
}