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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxM = 24;
int res[1 << maxM];

void calc(int l, int r) {
	if (l == r) {
		return;
	}
	calc(l, (l + r) / 2);
	calc((l + r) / 2 + 1, r);

	for (int i = (l + r) / 2 + 1, j = l; i <= r; ++i, ++j) {
		res[i] += res[j];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int mask = 0;
		for (int j = 0; j < 3; ++j) {
			mask |= (1 << (s[j] - 'a'));
		}
		++res[mask];
	}
	calc(0, (1 << 24) - 1);
	int ans = 0;
	for (int i = 0; i < (1 << 24); ++i) {
		ans ^= (n - res[i]) * (n - res[i]);
	}
	printf("%d\n", ans);


	return 0;
}