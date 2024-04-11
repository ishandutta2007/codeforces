#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m, k;
int a[maxN], b[maxN], c[maxN];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	long long res = 0;
	for (int i = 1; i <= k; ++i) {
		int p;
		scanf("%d", &p);
		for (int j = 1; j <= m; ++j) {
			if (p >= a[j] && p <= b[j]) {
				res += (long long)(c[j] + p - a[j]);
			}
		}
	}

	cout << res << endl;

	return 0;
}