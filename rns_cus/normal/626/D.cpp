#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100010

int gas[N];
long long tot[N];

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", a + i);
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (a[i] > a[j]) {
				gas[a[i] - a[j]] ++;
			}
		}
	}

	for (int i = 1; i <= 5000; i ++) {
		for (int j = 1; j <= 5000; j ++) {
			tot[i+j] += gas[i] * gas[j];
		}
	}

	ll total = 0, temp = 0;
	for (int i = 1; i <= 5000; i ++) {
		total += temp * gas[i];
		temp += tot[i];
	}

	ll tmp = n * (n - 1) / 2;

	printf("%.10lf\n", 1.0 * total / tmp / tmp / tmp);
}