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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int r[maxN];
int p[maxN], values[maxN];

void solve(int n, int p[], int values[]) {
	if (n == 1) {
		r[p[0]] = values[0];
		return;
	}

	int x = (n + 1) / 2;
	int y = n - x;

	int *p1 = new int[x];
	int *p2 = new int[y];
	int *v1 = new int[x];
	int *v2 = new int[y];

	int p1cnt = 0, p2cnt = 0, v1cnt = 0, v2cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			p1[p1cnt++] = p[i];
		} else {
			p2[p2cnt++] = p[i];
		}

		if (i % 2 == 1 || (i + 1) == n) {
			v1[v1cnt++] = values[i];
		} else {
			v2[v2cnt++] = values[i];
		}
	}
	solve(x, p1, v1);
	solve(y, p2, v2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		p[i] = i;
		values[i] = i;
	}
	solve(n + 1, p, values);
	long long res = 0;
	for (int i = 0; i <= n; ++i) {
		res += (long long)(i ^ r[i]);
	}
	printf("%I64d\n", res);
	for (int i = 0; i <= n; ++i) {
		printf("%d ", r[i]);
	}
	printf("\n");


	return 0;
}