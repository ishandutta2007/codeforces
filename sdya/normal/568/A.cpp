#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5000000;
bool p[maxN];

bool isGood(int n) {
	int m = 0;
	int on = n;
	while (n) {
		m = m * 10 + (n % 10);
		n /= 10;
	}
	return m == on;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[1] = true;
	for (int i = 2; i * i < maxN; ++i) {
		if (p[i]) {
			continue;
		}
		for (int j = i * i; j < maxN; j += i) {
			p[j] = true;
		}
	}

	long long u, v;
	cin >> u >> v;
	long long x = 0, y = 0;
	int res = 1;
	for (int i = 1; i < maxN; ++i) {
		if (!p[i]) {
			++x;
		}
		if (isGood(i)) {
			++y;
		}
		if (x * v <= u * y) {
			res = i;
		}
	}

	printf("%d\n", res);

	return 0;
}