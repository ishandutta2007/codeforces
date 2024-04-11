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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int d[maxN];
int n, m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		++d[u];
		++d[v];
	}

	long long N = n;
	long long total = N * (N - 1) * (N - 2) / 6LL;
	long long add = 0;
	for (int i = 1; i <= n; ++i) {
		long long x = d[i];
		long long y = n - 1 - x;
		add += x * y;
	}
	cout << total - (add / 2) << endl;


	return 0;
}