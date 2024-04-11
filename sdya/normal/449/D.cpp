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

const int maxN = 1100000;
const long long P = 1000000007LL;
int n, a[maxN];
int d[maxN], c[maxN];

int p[maxN];

const int maxK = 25;
int b[maxK], m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p[i] = (p[i - 1] + p[i - 1]);
		if (p[i] >= P) {
			p[i] -= P;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++d[a[i]];
	}
	/*n = 1000000;
	for (int i = 0; i < n; ++i) {
		a[i] = i;
		++d[a[i]];
	}*/

	for (int i = (1 << 20) - 1; i >= 0; --i) {
		if (d[i] == 0) {
			continue;
		}
		int b = -1;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j)) {
				b = j;
				break;
			}
		}
		if (b >= 0) {
			d[i ^ (1 << b)] += d[i];
			int m = i ^ (1 << b);
			for (int j = m; j; j = (j - 1) & m) {
				c[(1 << b) + j] += d[i];
			}
			c[(1 << b)] += d[i];
		} else {
			c[0] += d[i];
		}
	}

	//cerr << clock() << endl;

	int res = 0;
	for (int i = 0; i < (1 << 20); ++i) {
		int cnt = 0;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j)) {
				++cnt;
			}
		}
		if (cnt % 2 == 1) {
			res -= p[c[i]];
			if (res < 0) {
				res += P;
			}
		} else {
			res += p[c[i]];
			if (res >= P) {
				res -= P;
			}
		}
	}

	cout << res << endl;

	return 0;
}