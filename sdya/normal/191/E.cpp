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
const long long inf = 1000000000000000000LL;
int n, m;
long long k;
long long a[maxN];
long long b[maxN];

int t[maxN];

void update(int k, int delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += delta;
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
	return get(r) - get(l - 1);
}

bool check(long long value) {
	memset(t, 0, sizeof(t));
	long long s = 0;
	update(lower_bound(b, b + m, s) - b, +1);
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		int id = upper_bound(b, b + m, s - value) - b;
		--id;
		res += get(id);
		update(lower_bound(b, b + m, s) - b, +1);
	}
	return res >= k;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%I64d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
		b[i] = a[i];
		if (i > 0) {
			b[i] += b[i - 1];
		}
	}
	b[n] = 0;
	sort(b, b + n + 1);
	m = unique(b, b + n + 1) - b;

	long long left_bound = -inf, right_bound = inf;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (check(right_bound)) {
		printf("%I64d\n", right_bound);
	} else {
		printf("%I64d\n", left_bound);
	}


	return 0;
}