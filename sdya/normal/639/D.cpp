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

const int maxN = 210000;
const long long inf = 1000000000000000000LL;
int n, k, b, c;
long long t[maxN];

long long S;

long long get(long long n) {
	if (5 * c <= b) {
		return (long long)(c) * n;
	}
	return (n / 5LL) * b + (n % 5LL) * c;
}

long long nextRem(long long x, long long rem) {
	while ((x % 5 + rem) % 5 != 0) {
		++x;
	}
	return x;
}

long long solve(long long rem) {
	multiset < long long > M;
	long long shift = 0;
	long long sum = 0;

	long long start = nextRem(t[k - 1], rem);

	for (int i = 0; i < k; ++i) {
		long long value = get(start - t[i]);
		sum += value;
		M.insert(value);
	}

	long long res = inf;
	for (int i = k - 1; i < n; ++i) {
		res = min(res, sum);

		if (i + 1 == n) {
			break;
		}
		long long nstart = nextRem(t[i + 1], rem);
		long long buf = get(nstart - start);

		sum += buf * (long long)(k);
		shift += buf;

		long long value = get(nstart - t[i + 1]);
		M.insert(value - shift);
		sum += value;

		long long worst = *M.rbegin();
		M.erase(M.find(worst));
		worst += shift;
		sum -= worst;
		start = nstart;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &k, &b, &c);
	for (int i = 0; i < n; ++i) {
		int r;
		scanf("%d", &r);
		t[i] = r;
	}
	sort(t, t + n);

	S = get(5);
	long long res = inf;
	for (int rem = 0; rem < 5; ++rem) {
		res = min(res, solve(rem));
	}
	cout << res << endl;


	return 0;
}