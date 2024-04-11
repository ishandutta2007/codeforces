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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int cnt[maxN], n;
long long d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}

	for (int i = 1; i < maxN; ++i) {
		d[i] = d[i - 1];
		long long current = (long long)(i) * (long long)(cnt[i]);
		if (i - 2 >= 0) {
			current += d[i - 2];
		}
		d[i] = max(d[i], current);
	}

	cout << d[maxN - 1] << endl;

	return 0;
}