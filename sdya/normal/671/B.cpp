#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 510000;
int n, k;
int c[maxN];
long long s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
	}
	sort(c, c + n);
	for (int i = 0; i < n; ++i) {
		s[i] = c[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	long long boundr = (s[n - 1] + n - 1) / n;
	long long boundl = (s[n - 1]) / n;

	int r = -1;
	{
		long long L = boundr, R = 1000000000LL;
		while (R - L > 1) {
			long long m = (L + R) / 2;

			long long sum = 0;
			for (int i = 0; i < n; ++i) {
				if (c[i] > m) {
					sum += c[i] - m;
				}
			}
			if (sum <= (long long)(k)) {
				R = m;
			} else {
				L = m;
			}
		}

		r = R;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			if (c[i] > L) {
				sum += c[i] - L;
			}
		}
		if (sum <= (long long)(k)) {
			r = L;
		}
	}

	int l = -1;
	{
		long long L = 0, R = boundl;
		while (R - L > 1) {
			long long m = (L + R) / 2;

			long long sum = 0;
			for (int i = 0; i < n; ++i) {
				if (c[i] < m) {
					sum += m - c[i];
				}
			}
			if (sum <= (long long)(k)) {
				L = m;
			} else {
				R = m;
			}
		}

		l = L;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			if (c[i] < R) {
				sum += R - c[i];
			}
		}
		if (sum <= (long long)(k)) {
			l = R;
		}
	}

	cout << r - l << endl;

	return 0;
}