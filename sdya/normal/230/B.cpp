#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxN = 1100000;
bool p[maxN];

long long getRoot(long long n) {
	long long d = sqrt((double)(n));
	for (long long i = d - 1; i <= d + 1; ++i) {
		if (i * i == n && i > 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	p[1] = true;
	for (int i = 2; i * i < maxN; ++i) {
		if (p[i]) {
			continue;
		}
		for (int j = i * i; j < maxN; j += i) {
			p[j] = true;
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long m;
		scanf("%I64d", &m);
		long long d = getRoot(m);
		if (d != -1 && !p[d]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}