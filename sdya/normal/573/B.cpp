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

const int maxN = 110000;
int n, a[maxN];
int l[maxN], r[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int old = l[i - 1];
		if (a[i] > old) {
			l[i] = old + 1;
		} else {
			l[i] = a[i];
		}
	}
	for (int i = n; i >= 1; --i) {
		int old = r[i + 1];
		if (a[i] > old) {
			r[i] = old + 1;
		} else {
			r[i] = a[i];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = max(res, min(l[i], r[i]));
	}
	printf("%d\n", res);

	return 0;
}