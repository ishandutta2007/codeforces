#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int a[maxN], b[maxN];
int c[maxN], p[maxN];
int n;

inline int getNext(int j) {
	if (j + 1 == n + n) {
		return 0;
	}
	return j + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
		--b[i];
	}

	for (int i = 0; i < n; ++i) {
		c[a[i]] = rand() % 2;
		c[b[i]] = 1 - c[a[i]];

		p[a[i]] = b[i];
		p[b[i]] = a[i];
	}

	while (true) {
		bool updates = false;
		for (int i = 0; i < 2 * n; ++i) {
			int j = getNext(i);
			int k = getNext(j);

			if (c[i] == c[j] && c[j] == c[k]) {
				updates = true;
				int x = rand() % 3;
				if (x == 0) {
					c[i] ^= 1;
					c[p[i]] ^= 1;
				} else if (x == 1) {
					c[j] ^= 1;
					c[p[j]] ^= 1;
				} else {
					c[k] ^= 1;
					c[p[k]] ^= 1;
				}
			}
		}
		if (!updates) {
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", c[a[i]] + 1, c[b[i]] + 1);
	}


	return 0;
}