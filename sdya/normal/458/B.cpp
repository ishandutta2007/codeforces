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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m;
int a[maxN], b[maxN];

long long calc(int a[], int n, int b[], int m) {
	long long sA = 0, sB = 0;
	for (int i = 0; i < n; ++i) {
		sA += a[i];
	}
	for (int i = 0; i < m; ++i) {
		sB += b[i];
	}

	long long res = sA;
	for (int i = m - 2; i >= 0; --i) {
		res += min(sA, (long long)(b[i]));
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}

	sort(a, a + n);
	sort(b, b + m);

	long long res = min(calc(a, n, b, m), calc(b, m, a, n));
	cout << res << endl;


	return 0;
}