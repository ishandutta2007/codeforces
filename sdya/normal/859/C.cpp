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

const int maxN = 60;
int n;
int a[maxN];
int d[maxN][maxN];
int s[maxN];

int sum(int l, int r) {
	return s[r] - (l == 0 ? 0 : s[l - 1]);
}

int calc(int l, int r) {
	if (d[l][r] != -1) {
		return d[l][r];
	}

	if (l == r) {
		return d[l][r] = a[l];
	}

	int res = 0;
	res = max(res, calc(l + 1, r));
	res = max(res, a[l] + sum(l + 1, r) - calc(l + 1, r));

	return d[l][r] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		s[i] = a[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = -1;
		}
	}

	int res = calc(0, n - 1);
	cout << s[n - 1] - res << " " << res << endl;

	return 0;
}