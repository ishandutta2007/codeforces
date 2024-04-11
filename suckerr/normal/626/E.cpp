#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
long long sum[N];

int apos, anum;
double ans = -1e9;

bool found(double lower, bool print) {
	int extend = 0;
	for (int pivot = 1; pivot <= n; pivot++) {
		extend++;
		double base = a[pivot] + lower;
		while (pivot - extend < 1 || n - extend < pivot) {
			extend--;
		}
		while (extend && a[pivot - extend] + a[n - extend + 1] < base * 2) {
			extend--;
		}
		if (sum[pivot] - sum[pivot - extend - 1] + sum[n] - sum[n - extend] >= (extend * 2 + 1) * base) {
			if (print) {
				printf("%d\n", extend * 2 + 1);
				for (int i = pivot - extend; i <= pivot; i++) {
					printf("%d%c", a[i], i == pivot && extend == 0 ? '\n' : ' ');
				}
				for (int i = n - extend + 1; i <= n; i++) {
					printf("%d%c", a[i], i == n ? '\n' : ' ');
				}
			}
			return true;
		}
	}

	extend = 0;
	for (int pivot = 1; pivot < n; pivot++) {
		extend++;
		double base = (a[pivot] + a[pivot + 1]) / 2. + lower;
		while (pivot - extend < 0 || n - extend < pivot) {
			extend--;
		}
		while (extend > 1 && a[pivot - extend + 1] + a[n - extend + 2] < base * 2) {
			extend--;
		}
		if (sum[pivot] - sum[pivot - extend] + sum[n] - sum[n - extend + 1] + a[pivot + 1] >= extend * 2 * base) {
			if (print) {
				printf("%d\n", extend * 2);
				for (int i = pivot - extend + 1; i <= pivot + 1; i++) {
					printf("%d%c", a[i], i == pivot + 1 && extend == 2 ? '\n' : ' ');
				}
				for (int i = n - extend + 2; i <= n; i++) {
					printf("%d%c", a[i], i == n ? '\n' : ' ');
				}
			}
			return true;
		}
	}

	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	a[0] = -1e9;

	double l = 0, r = 1e6;
	for (int times = 0; times < 60; times++) {
		double mid = (l + r) / 2;
		if (found(mid, 0)) {
			l = mid;
		} else {
			r = mid;
		}
	}

	found(l, 1);
	return 0;
}