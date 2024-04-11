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

const int maxN = 310000;
const int maxD = 50;
const int maxI = 30000000;
int n, a[maxN];
int p[maxN], q[maxN];
int pos[maxN];
int order[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 2; i <= n; ++i) {
		q[a[i]] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		q[a[i]] = 0;
		p[a[i - 1]] = 1;
		int v = a[i];

		for (int j = i - 1; j >= i - maxD && j >= 1; --j) {
			int w = v + v - a[j];
			if (w >= 1 && w <= n && q[w]) {
				printf("YES\n");
				return 0;
			}
		}

		for (int j = i + 1; j <= i + maxD && j <= n; ++j) {
			int w = v + v - a[j];
			if (w >= 1 && w <= n && p[w]) {
				printf("YES\n");
				return 0;
			}
		}
	}

	printf("NO\n");

	return 0;
}