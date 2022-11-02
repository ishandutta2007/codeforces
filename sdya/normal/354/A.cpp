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

const int maxN = 110000;
int n, l, r, ql, qr;
int a[maxN], s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i] = a[i] + s[i - 1];
	}

	long long best = 1000000000000000000LL;
	for (int x = 0; x <= n; ++x) {
		long long score = (long long)(s[x]) * (long long)(l) + (long long)(s[n] - s[x]) * (long long)(r);
		int y = n - x;

		if (y > x + 1) {
			score += (long long)(y - x - 1) * (long long)(qr);
		}
		if (x > y + 1) {
			score += (long long)(x - y - 1) * (long long)(ql);
		}
		best = min(best, score);
	}
	cout << best << endl;

	return 0;
}