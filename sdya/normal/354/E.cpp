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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct C {
	int a[6];
};

int parent[20][5];
int p[20][5];
int digits[20], m;
C ways[1000];
int sum[1000];
int cntW;
bool dp[20][5];

int u[100], v[100];

void rec(int k, C current) {
	if (k == 6) {
		sum[cntW] = 0;
		for (int i = 0; i < 6; ++i) {
			sum[cntW] += current.a[i];
		}
		ways[cntW++] = current;
		return;
	}
	current.a[k] = 0;
	rec(k + 1, current);
	current.a[k] = 4;
	rec(k + 1, current);
	current.a[k] = 7;
	rec(k + 1, current);
}

void solve() {
	long long n;
	cin >> n;
	m = 0;
	while (n) {
		digits[m++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 5; ++j) {
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (!dp[i][j]) {
				continue;
			}

			for (int k = 0; k < cntW; ++k) {
				if (u[j + sum[k]] == digits[i]) {
					dp[i + 1][v[j + sum[k]]] = true;
					parent[i + 1][v[j + sum[k]]] = k;
					p[i + 1][v[j + sum[k]]] = j;
				}
			}
		}
	}
	if (!dp[m][0]) {
		printf("-1\n");
		return;
	}
	vector < long long > r(6);
	int u = m, v = 0;
	while (u != 0) {
		int index = parent[u][v];
		for (int i = 0; i < 6; ++i) {
			r[i] = r[i] * 10LL + ways[index].a[i];
		}
		v = p[u][v];
		--u;
	}
	for (int i = 0; i < 6; ++i) {
		printf("%I64d", r[i]);
		if (i == 5) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	rec(0, C());
	for (int i = 0; i < 100; ++i) {
		u[i] = i % 10;
		v[i] = i / 10;
	}

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}

	//cerr << clock() << endl;

	return 0;
}