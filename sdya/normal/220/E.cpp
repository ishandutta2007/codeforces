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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, a[maxN];
long long k;

int t1[maxN], t2[maxN];

void update(int t[], int k, int value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += value;
	}
}

int get(int t[], int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int get(int t[], int l, int r) {
	if (l > r) {
		return 0;
	}
	return get(t, r) - get(t, l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%I64d", &n, &k);
	vector < int > b;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		++a[i];
	}

	long long res = 0;
	long long total = 0;
	update(t1, a[1], 1);

	for (int i = n; i > 1; --i) {
		total += get(t2, 1, a[i] - 1);
		total += get(t1, a[i] + 1, n);
		update(t2, a[i], 1);
	}

	int bound = 2;
	for (int i = 1; i < n; ++i) {
		while (bound <= n && total > k) {
			total -= get(t1, a[bound] + 1, n);
			total -= get(t2, 1, a[bound] - 1);
			update(t2, a[bound], -1);

			++bound;
		}

		if (bound == n + 1) {
			break;
		}

		res += (n + 1 - bound);
		if (i + 1 == n) {
			continue;
		}

		if (bound == i + 1) {
			total -= get(t1, a[bound] + 1, n);
			total -= get(t2, 1, a[bound] - 1);
			update(t2, a[bound], -1);
			++bound;
		}

		{
			total += get(t1, a[i + 1] + 1, n);
			total += get(t2, 1, a[i + 1] - 1);
			update(t1, a[i + 1], 1);
		}
	}

	printf("%I64d\n", res);

	return 0;
}