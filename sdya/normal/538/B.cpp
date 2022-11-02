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

vector < int > a;

void gen(int current) {
	if (current > 1000000) {
		return;
	}
	if (current <= 1000000) {
		a.push_back(current);
	}
	gen(current * 10 + 1);
	gen(current * 10);
}

const int maxN = 1010000;
const int inf = 1000000000;
int d[maxN];
int p[maxN];
int n;

void precalc() {
	for (int i = 0; i <= n; ++i) {
		d[i] = inf;
	}
	d[0] = 0;
	for (int i = 0; i <= n; ++i) {
		if (d[i] == inf) {
			continue;
		}
		for (int j = 0; j < a.size(); ++j) {
			if (i + a[j] <= n && d[i] + 1 < d[i + a[j]]) {
				d[i + a[j]] = d[i] + 1;
				p[i + a[j]] = a[j];
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gen(1);
	sort(a.begin(), a.end());
	scanf("%d", &n);
	precalc();

	int res = d[n];
	printf("%d\n", res);
	vector < int > ans;
	int m = n;
	while (m != 0) {
		ans.push_back(p[m]);
		m -= p[m];
	}
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}