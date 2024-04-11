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

const int maxN = 5100;
int d[maxN], a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		double pos;
		scanf("%d%lf", &a[i], &pos);
	}

	d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (a[j] <= a[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	int res = *max_element(d + 1, d + n + 1);
	printf("%d\n", n - res);

	return 0;
}