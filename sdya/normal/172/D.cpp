#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 11000000;
int a[maxN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i * i <= 10000000; ++i) {
		int step = i * i;
		for (int j = step; j <= 10000000; j += step)
			a[j] = step;
	}

	long long res = 0;
	for (int i = n; i < n + m; ++i) {
		res += (long long)(i / a[i]);
	}

	cout << res << endl;

	return 0;
}