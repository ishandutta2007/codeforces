#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;
long long A, cf, cm, M;
pair < long long, int > a[maxN];
long long s[maxN];
long long r[maxN];

bool check(long long m, int cnt, long long rem) {
	int index = lower_bound(a, a + cnt, make_pair(m, -1)) - a;
	--index;
	if (index < 0) {
		return true;
	}
	long long sum = s[index];
	return m * (long long)(index + 1) - sum <= rem;
}

long long solve(long long k, long long &bound) {
	long long needed = k * A - (s[n - 1] - (k == n ? 0 : s[n - k - 1]));
	if (needed > M) {
		return 0;
	}
	long long rem = M - needed;

	long long l = 0, r = A;
	while (r - l > 1) {
		long long m = (l + r) / 2;
		if (check(m, n - k, rem)) {
			l = m;
		} else {
			r = m;
		}
	}
	bound = l;
	if (check(r, n - k, rem)) {
		bound = r;
	}
	return bound * cm + k * cf;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &M);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		s[i] = a[i].first;
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].first == A) {
			++mx;
		}
	}
	long long res = 0;
	int cnt = 0;
	long long b = 0;
	for (int i = mx; i <= n; ++i) {
		long long bound = 0;
		long long d = solve(i, bound);
		if (d > res) {
			res = d;
			cnt = i;
			b = bound;
		}
	}
	printf("%I64d\n", res);

	for (int i = 0; i < n; ++i) {
		r[a[i].second] = a[i].first;
	}
	for (int i = n - cnt; i < n; ++i) {
		r[a[i].second] = A;
	}
	for (int i = 0; i < n - cnt; ++i) {
		if (a[i].first < b) {
			r[a[i].second] = b;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%I64d ", r[i]);
	}
	printf("\n");


	return 0;
}