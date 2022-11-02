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

const int maxN = 2100000;

int t[maxN];

void update(int k, int value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += value;
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int get(int l, int r) {
	if (l > r) {
		return 0;
	}
	return get(r) - get(l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, k;
	cin >> n >> k;
	if (n - k < k) {
		k = n - k;
	}
	long long res = 1;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		int y = x + k;
		res += get(x + 1, y - 1) + 1;
		update(y % n, 1);
		update(n + (y % n), 1);
		update(x, 1);
		update(x + n, 1);
		printf("%I64d ", res);
		x = (x + k) % n;
	}
	printf("\n");

	return 0;
}