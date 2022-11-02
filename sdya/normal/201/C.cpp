#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, a[maxN];
long long s[maxN];
long long p[maxN], q[maxN], r[maxN];
long long even[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + (long long)(a[i] / 2) * 2LL;
	}

	for (int i = 1; i < n; ++i) {
		int add = (a[i] % 2 == 0 ? 1 : 0);
		even[i] = even[i - 1] + add;
	}

	for (int i = n - 1; i >= 1; --i) {
		if (a[i] == 1) {
			p[i] = 0;
		} else {
			p[i] = p[i + 1] + (long long)(a[i] / 2) * 2LL;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i - 1] == 1) {
			r[i] = 0;
		} else {
			r[i] = r[i - 1] + (long long)(a[i - 1] / 2) * 2LL;
		}
	}


	q[1] = 0;
	for (int i = 1; i < n; ++i) {
		q[i + 1] = q[i] + (long long)(a[i]);
		if (a[i] % 2 == 0) {
			--q[i + 1];
		}
		if (a[i] > 1) {
			q[i + 1] = max(q[i + 1], r[i + 1]);
		}
	}

	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res = max(res, q[i] + p[i]);
	}
	cout << res << endl;

	return 0;
}